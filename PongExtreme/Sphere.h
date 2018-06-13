#pragma once
class Sphere
{
private:
	GLuint vao;

	GLuint colorBuffer;
	GLuint vertexBuffer;
	GLuint normalBuffer;

	GLfloat* colorBufferData;
	GLfloat* vertexBufferData;
	GLfloat* normalBufferData;

	GLuint lats;
	GLuint longs;
public:
	Sphere(GLuint vao, GLuint lats, GLuint longs);
	~Sphere();
	void draw();
};

