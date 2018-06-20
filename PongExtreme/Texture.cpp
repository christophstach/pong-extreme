#include "stdafx.h"
#include "Texture.h"
#include "lib/stb/stb_image.h"

Texture::Texture(const char * filePath)
{
	this->filePath = filePath;
	this->renderId = 0;
	this->width = 0;
	this->height = 0;
	this->nrChannels = 0;
	this->localBuffer = nullptr;

	stbi_set_flip_vertically_on_load(1);
	this->localBuffer = stbi_load(this->filePath, &this->width, &this->height, &this->nrChannels, 4);

	glGenTextures(1, &this->renderId);
	glBindTexture(GL_TEXTURE_2D, this->renderId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->localBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (this->localBuffer) {
		stbi_image_free(this->localBuffer);
	}
}

Texture::~Texture()
{
	glDeleteTextures(1, &this->renderId);
}

void Texture::bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, this->renderId);
}

void Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
