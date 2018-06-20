#pragma once

class TextureLoader {
public:
	TextureLoader();
	GLuint loadStb(const char * imagePath);
	GLuint loadCustomBmp(const char * imagePath);
	GLuint loadDds(const char * imagePath);
};