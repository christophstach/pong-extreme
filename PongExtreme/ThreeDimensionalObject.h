#pragma once
class ThreeDimensionalObject
{
private:
	ObjectLoader * objectLoader;
	GLuint vao;

	GLuint vertexBuffer;
	GLuint uvBuffer;
	GLuint normalBuffer;

	int vertexBufferDataSize;
public:
	ThreeDimensionalObject(ObjectLoader* objectLoader, GLuint vao, const char* objectPath);
	void draw();
};

