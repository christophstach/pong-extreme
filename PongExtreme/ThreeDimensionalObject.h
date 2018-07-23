#pragma once
class ThreeDimensionalObject
{
private:
	ObjectLoader * objectLoader;
	GLuint vao;
	ObjectDefinition* objectDefinition;

	GLuint vertexBuffer;
	GLuint uvBuffer;
	GLuint normalBuffer;

	int vertexBufferDataSize;
public:
	BoundingBox * boundingBox;

	ThreeDimensionalObject(ObjectLoader* objectLoader, GLuint vao, const char* objectPath);
	void calculateBoundingBox();
	void draw();
	~ThreeDimensionalObject();
};

