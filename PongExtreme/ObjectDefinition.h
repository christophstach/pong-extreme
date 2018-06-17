#pragma once
class ObjectDefinition
{
public:
	std::vector<glm::vec3> vertexBufferData;
	std::vector<glm::vec2> uvBufferData;
	std::vector<glm::vec3> normalBufferData;

	ObjectDefinition();
};

