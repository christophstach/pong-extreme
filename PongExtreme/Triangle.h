#pragma once
class Triangle
{
private:
	GLuint vertexBuffer;
public:
	void init();
	void draw();

	Triangle();
	~Triangle();
};

