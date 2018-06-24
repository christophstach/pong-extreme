#pragma once
class GameObject
{
protected:
	ThreeDimensionalObject * object;
	BoundingBox * boundingBox = new BoundingBox();
public:
	virtual glm::mat4 transform(glm::mat4 model);
	virtual BoundingBox * getBoundingBox();
	virtual GameObject* transformBoundingBox(glm::vec3 translateValue, glm::vec3 scaleValue);
	virtual GameObject* draw();
};

