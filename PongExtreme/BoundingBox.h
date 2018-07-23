#pragma once
class BoundingBox
{
public:
	glm::vec4 min;
	glm::vec4 max;
	BoundingBox();
	void toConsole();
	~BoundingBox();
};

