#pragma once

class TextureLoader {
public:
	GLuint loadCustomBmp(const char * imagePath);
	GLuint loadDds(const char * imagePath);
};