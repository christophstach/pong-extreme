#pragma once
class LeftBar
{
private: 
	Cube * cube;
public:
	LeftBar();
	~LeftBar();

	void init();
	glm::mat4 draw(glm::mat4 model, float position);
};

