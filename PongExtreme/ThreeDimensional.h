#pragma once
class ThreeDimensional
{
public:
	virtual glm::mat4 transform(glm::mat4 model);
	virtual void draw();
};

