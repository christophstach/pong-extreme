#pragma once

class ObjectLoader
{
public:
	bool load(
		const char* path,
		std::vector<glm::vec3> &outVertices,
		std::vector<glm::vec2> &outUvs,
		std::vector<glm::vec3> &outNormals
	);

	bool loadAssImp(
		const char* path,
		std::vector<unsigned short> &indices,
		std::vector<glm::vec3> &vertices,
		std::vector<glm::vec2> &uvs,
		std::vector<glm::vec3> &normals
	);
};