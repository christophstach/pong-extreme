#pragma once
class GameObject
{
protected:
	ThreeDimensionalObject * object;
	BoundingBox * boundingBox = new BoundingBox();
public:
	virtual glm::mat4 transform(glm::mat4 model);
	virtual void transformBoundingBox(glm::vec3 translateValue, glm::vec3 scaleValue);
	virtual BoundingBox * getBoundingBox();
	virtual void draw();
};

