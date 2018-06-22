#include "stdafx.h"
#include "ThreeDimensionalObject.h"


ThreeDimensionalObject::ThreeDimensionalObject(ObjectLoader* objectLoader, GLuint vao, const char* objectPath)
{
	this->vao = vao;
	this->objectLoader = objectLoader;
	this->boundingBox = new BoundingBox();

	this->objectDefinition = this->objectLoader->load(objectPath);
	this->vertexBufferDataSize = this->objectDefinition->vertexBufferData.size();

	glBindVertexArray(this->vao);

	glGenBuffers(1, &this->vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, this->objectDefinition->vertexBufferData.size() * sizeof(glm::vec3), &this->objectDefinition->vertexBufferData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &this->uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, this->objectDefinition->uvBufferData.size() * sizeof(glm::vec2), &this->objectDefinition->uvBufferData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &this->normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, this->objectDefinition->normalBufferData.size() * sizeof(glm::vec3), &this->objectDefinition->normalBufferData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindVertexArray(0);

	this->calculateBoundingBox();
}

void ThreeDimensionalObject::calculateBoundingBox()
{
	std::vector<glm::vec3> vertices = this->objectDefinition->vertexBufferData;

	this->boundingBox->min = glm::vec4(vertices[0].x, vertices[0].y, vertices[0].z, 0.0);
	this->boundingBox->max = glm::vec4(vertices[0].x, vertices[0].y, vertices[0].z, 0.0);

	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].x < this->boundingBox->min.x) this->boundingBox->min.x = vertices[i].x;
		if (vertices[i].y < this->boundingBox->min.y) this->boundingBox->min.y = vertices[i].y;
		if (vertices[i].z < this->boundingBox->min.z) this->boundingBox->min.z = vertices[i].z;
		if (vertices[i].x > this->boundingBox->max.x) this->boundingBox->max.x = vertices[i].x;
		if (vertices[i].y > this->boundingBox->max.y) this->boundingBox->max.y = vertices[i].y;
		if (vertices[i].z > this->boundingBox->max.z) this->boundingBox->max.z = vertices[i].z;
	}
}


void ThreeDimensionalObject::draw()
{
	glBindVertexArray(this->vao);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glDrawArrays(GL_TRIANGLES, 0, this->vertexBufferDataSize);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindVertexArray(0);
}
