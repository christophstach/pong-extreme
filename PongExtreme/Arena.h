#pragma once
class Arena : public GameObject
{
private:
	ThreeDimensionalObject* object;
public:
	Arena(ObjectLoader* objectLoader, GLuint vao);
	glm::mat4 transform(glm::mat4 model);
	void draw();
};

