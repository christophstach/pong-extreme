#pragma once
class ShaderLoader
{
public:
	ShaderLoader();
	~ShaderLoader();
	GLuint* load(const char* vertexFilePath, const char* fragmentFilePath);
};

