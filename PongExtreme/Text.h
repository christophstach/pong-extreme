#pragma once
class Text
{
private:
	const char * text = nullptr;
	int x = 0;
	int y = 0;
	int size = 0;

	TextureLoader * textureLoader;
	ShaderLoader * shaderLoader;

	GLuint vao;
	GLuint shaderId;
	GLuint uniformId;
	GLuint vertexBuffer;
	GLuint uvBuffer;
public:
	Text();
	Text* print(float x, float y, const char *text);

};

