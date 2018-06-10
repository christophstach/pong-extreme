#pragma once
class Cube
{
private: 
	GLuint colorBuffer;
	GLuint vertexBuffer;
public:
	void init();
	void draw();
	Cube();
	~Cube();
};

