#pragma once
class RightBar
{
	Cube * cube;
public:
	RightBar();
	~RightBar();

	void init();
	glm::mat4 draw(glm::mat4 model);
};

