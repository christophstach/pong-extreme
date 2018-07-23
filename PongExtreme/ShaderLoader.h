#pragma once
class ShaderLoader
{
public:
	ShaderLoader();
	GLuint load(const char* vertexFilePath, const char* fragmentFilePath);
	~ShaderLoader();
};

