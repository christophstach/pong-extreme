#pragma once
class Arena : public ThreeDimensional
{
private:
	GLuint vao;
	ThreeDimensionalObject* object;
public:
	Arena(GLuint vao, ObjectLoader* objectLoader, TextureLoader* textureLoader);
	glm::mat4 transform(glm::mat4 model);
	void draw();
};

