#pragma once
class LeftBar: public ThreeDimensional
{
private: 
	ThreeDimensionalObject* object;
	float position = 0;
public:
	LeftBar(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	void setPosition(float position);
	void draw();
};

