#include "stdafx.h"
#include "WaveSound.h"

WaveSound::WaveSound(const char * fileName)
{
	//ok = false;
	this->buffer = 0;
	//HInstance = GetModuleHandle(0);

	std::ifstream file(fileName, std::ios::binary);

	if (!file)
	{
		printf("Wave::file error:  %s", fileName);
		return;
	}

	file.seekg(0, std::ios::end);   // get length of file
	int length = file.tellg();
	this->buffer = new char[length];    // allocate memory
	file.seekg(0, std::ios::beg);   // position to start of file
	file.read(buffer, length);  // read entire file

	file.close();
}

void WaveSound::play(bool async)
{
	if (async)
		PlaySound((LPCWSTR)this->buffer, NULL, SND_MEMORY | SND_ASYNC);
	else
		PlaySound((LPCWSTR)this->buffer, NULL, SND_MEMORY);
}
