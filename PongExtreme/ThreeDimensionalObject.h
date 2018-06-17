#pragma once
class ThreeDimensionalObject
{
private:
	ObjectLoader * objectLoader;
	TextureLoader * textureLoader;

	GLuint vao;
	GLuint texture;

	GLuint vertexBuffer;
	GLuint uvBuffer; 
	GLuint normalBuffer;

	int vertexBufferDataSize;
public:
	ThreeDimensionalObject(GLuint vao, const char* filePath, ObjectLoader* objectLoader, TextureLoader* textureLoader);
	void draw();
};

