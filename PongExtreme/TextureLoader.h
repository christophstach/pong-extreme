#pragma once

class TextureLoader {
public:
	TextureLoader();
	GLuint loadStb(const char * imagePath, int mode = GL_CLAMP_TO_EDGE);
	GLuint loadCustomBmp(const char * imagePath);
	GLuint loadDds(const char * imagePath);
};