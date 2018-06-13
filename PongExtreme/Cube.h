#pragma once
class Cube
{
private:
	GLuint vao;
	GLuint vertexBuffer;
	GLuint colorBuffer;
public:
	Cube(GLuint vao);
	~Cube();
	void draw();
};

