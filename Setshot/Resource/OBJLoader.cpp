/*
	Setshot Project

	by MrOnlineCoder
	github.com/MrOnlineCoder | @MrOnlineCoder#4902

	(c) 2019

	License: see LICENSE file
*/
#include "OBJLoader.h"

#include <Logger/Logger.h>

#include <vector>

#include <tiny_obj_loader.h>

bool OBJModelLoader::loadFromFile(const char * path, Mesh & mesh) {
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::string warn;
	std::string err;

	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path);

	if (!err.empty()) {
		gLogger.tag("OBJLoader") << "tinyobj Error: " << err;
		return false;
	}

	if (!ret) return false;

	std::size_t nVertices = 0;

	for (const auto& shape : shapes) {
		for (const auto& index : shape.mesh.indices) {
			mesh.vertices.push_back(attrib.vertices[3 * index.vertex_index + 0]);
			mesh.vertices.push_back(attrib.vertices[3 * index.vertex_index + 1]);
			mesh.vertices.push_back(attrib.vertices[3 * index.vertex_index + 2]);

			if (attrib.texcoords.size() > 0) {
				mesh.texCoords.push_back(attrib.texcoords[2 * index.texcoord_index + 0]);
				mesh.texCoords.push_back(1.0f - attrib.texcoords[2 * index.texcoord_index + 1]);
			}

			if (attrib.normals.size() > 0) {
				mesh.normals.push_back(attrib.normals[3 * index.normal_index + 0]);
				mesh.normals.push_back(attrib.normals[3 * index.normal_index + 1]);
				mesh.normals.push_back(attrib.normals[3 * index.normal_index + 2]);
			}

			nVertices++;
		}
	}

	gLogger.tag("OBJLoader") << "Loaded .obj " << path << " with " << nVertices << " vertices.";
}
