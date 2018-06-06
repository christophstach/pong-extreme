#pragma once

class TextureLoader {
public:
	// Load a .BMP file using our custom loader
	GLuint loadCustomBmp(const char * imagePath);

	// Load a .TGA file using GLFW's own loader
	// Geht nicht mehr ab GLFW3
	//GLuint loadTGA_glfw(const char * imagePath);

	// Load a .DDS file using GLFW's own loader
	GLuint loadDds(const char * imagePath);
};