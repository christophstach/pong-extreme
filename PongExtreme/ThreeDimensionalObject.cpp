#include "stdafx.h"
#include "ThreeDimensionalObject.h"


ThreeDimensionalObject::ThreeDimensionalObject(GLuint programId, GLuint vao, const char* objectPath, const char* texturePath, ObjectLoader* objectLoader)
{
	this->vao = vao;
	this->programId = programId;
	this->objectLoader = objectLoader;

	ObjectDefinition* objectDefinition = this->objectLoader->load(objectPath);
	this->vertexBufferDataSize = objectDefinition->vertexBufferData.size();

	glBindVertexArray(this->vao);

	glGenBuffers(1, &this->vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, objectDefinition->vertexBufferData.size() * sizeof(glm::vec3), &objectDefinition->vertexBufferData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &this->uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, objectDefinition->uvBufferData.size() * sizeof(glm::vec2), &objectDefinition->uvBufferData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glGenBuffers(1, &this->normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, objectDefinition->normalBufferData.size() * sizeof(glm::vec3), &objectDefinition->normalBufferData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	if (texturePath) {
		this->texture = new Texture(texturePath);
		this->texture->bind(0);
		glUniform1i(glGetUniformLocation(this->programId, "myTextureSampler"), 0);
	}

	glBindVertexArray(0);
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
