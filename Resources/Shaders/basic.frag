#version 330 core
out vec4 outFragmentColor;

in vec2 sharedTexCoord;
in vec3 sharedNormal;
in vec3 sharedWorldPosition;

uniform sampler2D uTexture;
uniform vec3 uLightningSource;
uniform float uAmbientStrength;

vec3 calculateDiffuseColor() {
	vec3 nNormal = normalize(sharedNormal);
	vec3 lightDirection = normalize(uLightningSource - sharedWorldPosition);

	float diffuse = max(dot(nNormal, lightDirection), 0.0);

	return diffuse * vec3(1.0f, 1.0f, 1.0f);
}

vec3 calculateAmbientColor() {
	return uAmbientStrength * vec3(1.0f, 1.0f, 1.0f);
}

void main() {
	vec3 lightningColor = calculateAmbientColor() + calculateDiffuseColor();
	vec4 textureColor = texture(uTexture, sharedTexCoord);

	vec4 result = vec4(lightningColor, 1.0f) * textureColor;
	outFragmentColor = result;
}   