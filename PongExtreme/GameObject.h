#pragma once
class GameObject
{
protected:
	BoundingBox * boundingBox = new BoundingBox();
public:
	virtual glm::mat4 transform(glm::mat4 model);
	virtual BoundingBox * getBoundingBox();
	virtual void draw();
};

