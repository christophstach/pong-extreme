#include "stdafx.h"
#include "ThreeDimensionalObject.h"


ThreeDimensionalObject::ThreeDimensionalObject(const char* filePath, ObjectLoader* objectLoader, TextureLoader* textureLoader)
{
	this->textureLoader = textureLoader;
	this->objectLoader = objectLoader;

	this->objectLoader->load(filePath, vertices, uvs, normals);
	// Load the texture
	texture = this->textureLoader->loadCustomBmp("mandrill.bmp");

	glGenVertexArrays(1, &vertextArrayId);
	glBindVertexArray(vertextArrayId);

	// Ein ArrayBuffer speichert Daten zu Eckpunkten (hier xyz bzw. Position)

	glGenBuffers(1, &vertextArrayId); // Kennung erhalten
	glBindBuffer(GL_ARRAY_BUFFER, vertextArrayId); // Daten zur Kennung definieren
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);


	// Erst nach glEnableVertexAttribArray kann DrawArrays auf die Daten zugreifen...
	glEnableVertexAttribArray(0); // siehe layout im vertex shader: location = 0 
	glVertexAttribPointer(
		0,  // location = 0 
		3,  // Datenformat vec3: 3 floats fuer xyz 
		GL_FLOAT,
		GL_FALSE, // Fixedpoint data normalisieren ?
		0, // Eckpunkte direkt hintereinander gespeichert
		(void*)0
	); // abweichender Datenanfang ? 

	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2); // siehe layout im vertex shader 
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);


	glGenBuffers(1, &uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1); // siehe layout im vertex shader 
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
}


ThreeDimensionalObject::~ThreeDimensionalObject()
{
	glDeleteBuffers(1, &normalBuffer);
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &uvBuffer);
	glDeleteTextures(1, &texture);
}

void ThreeDimensionalObject::display()
{
	glBindVertexArray(vertextArrayId);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
