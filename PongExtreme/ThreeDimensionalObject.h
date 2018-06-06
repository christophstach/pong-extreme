#pragma once
class ThreeDimensionalObject
{
private:
	ObjectLoader * objectLoader;
	TextureLoader * textureLoader;

	GLuint vertextArrayId;
	GLuint texture;

	GLuint normalBuffer; // Hier alles analog für Normalen in location == 2
	GLuint vertexBuffer;
	GLuint uvBuffer; // Hier alles analog für Texturkoordinaten in location == 1 (2 floats u und v!)

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
public:
	ThreeDimensionalObject(const char* filePath, ObjectLoader* objectLoader, TextureLoader* textureLoader);
	~ThreeDimensionalObject();
	void display();
};

