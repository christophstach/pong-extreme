#pragma once
class Floor : public ThreeDimensional
{
private:
	ThreeDimensionalObject * object;
	float position = 0;
public:
	Floor(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	void draw();
};

