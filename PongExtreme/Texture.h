#pragma once
class Texture
{
private:
	GLuint renderId;
	const char* filePath;
	int width, height, nrChannels;
	unsigned char* localBuffer;
public:
	Texture(const char* filePath);
	~Texture();
		
	void bind(unsigned int slot = 0) const;
	void unbind() const;

	inline int getWidth() const { return this->width; };
	inline int getHeight() const { return this->height; };
};

