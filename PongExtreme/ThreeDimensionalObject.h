#pragma once
class ThreeDimensionalObject
{
private:
	ObjectLoader * objectLoader;
	GLuint programId;

	GLuint vao;
	Texture* texture;

	GLuint vertexBuffer;
	GLuint uvBuffer;
	GLuint normalBuffer;

	int vertexBufferDataSize;
public:
	ThreeDimensionalObject(GLuint programmid, GLuint vao, const char* objectPath, const char* texturePath, ObjectLoader* objectLoader);
	void draw();
};

