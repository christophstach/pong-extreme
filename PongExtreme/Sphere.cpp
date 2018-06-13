#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere(GLuint vao, GLuint lats, GLuint longs)
{
	this->vao = vao;
	this->lats = lats;
	this->longs = longs;

	this->vertexBufferData = new GLfloat[6 * (this->lats + 1) * (this->longs + 1)];
	this->normalBufferData = new GLfloat[6 * (this->lats + 1) * (this->longs + 1)];

	int index = 0;
	for (int i = 0; i <= this->lats; i++)
	{
		GLfloat lat0 = (GLfloat)M_PI * ((GLfloat)-0.5 + (GLfloat)(i - 1) / (GLfloat)this->lats);
		GLfloat z0 = sin(lat0);
		GLfloat zr0 = cos(lat0);

		GLfloat lat1 = (GLfloat)M_PI * ((GLfloat)-0.5 + (GLfloat)i / (GLfloat)this->lats);
		GLfloat z1 = sin(lat1);
		GLfloat zr1 = cos(lat1);

		for (int j = 0; j <= longs; j++)
		{
			GLfloat lng = (GLfloat)2 * (GLfloat)M_PI * (GLfloat)(j - 1) / (GLfloat)this->longs;
			GLfloat x = cos(lng);
			GLfloat y = sin(lng);

			this->normalBufferData[index] = x * zr0;
			this->vertexBufferData[index++] = x * zr0;
			this->normalBufferData[index] = y * zr0;
			this->vertexBufferData[index++] = y * zr0;
			this->normalBufferData[index] = z0;
			this->vertexBufferData[index++] = z0;
			this->normalBufferData[index] = x * zr1;
			this->vertexBufferData[index++] = x * zr1;
			this->normalBufferData[index] = y * zr1;
			this->vertexBufferData[index++] = y * zr1;
			this->normalBufferData[index] = z1;
			this->vertexBufferData[index++] = z1;
		}
	}

	glBindVertexArray(this->vao);

	glGenBuffers(1, &this->vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * (this->lats + 1) * (this->longs + 1), this->vertexBufferData, GL_STATIC_DRAW);

	glGenBuffers(1, &this->normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * (this->lats + 1) * (this->longs + 1), this->normalBufferData, GL_STATIC_DRAW);

	glBindVertexArray(0);
}


Sphere::~Sphere()
{
}

void Sphere::draw()
{
	glBindVertexArray(this->vao);

	
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, this->normalBuffer);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 2 * (this->lats + 1) * (this->longs + 1));
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(2);

	glBindVertexArray(0);
}