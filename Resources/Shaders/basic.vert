#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;

uniform mat4 uModelMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;

out vec2 sharedTexCoord;
out vec3 sharedNormal;
out vec3 sharedWorldPosition;

void main()
{
    gl_Position = uProjectionMatrix * uViewMatrix * uModelMatrix * vec4(aPos, 1.0);

	sharedWorldPosition = vec3(uModelMatrix * vec4(aPos, 1.0));
	sharedTexCoord = aTexCoord;
	sharedNormal = mat3(transpose(inverse(uModelMatrix))) * aNormal; 
}