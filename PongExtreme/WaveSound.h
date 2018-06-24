#pragma once
class WaveSound
{
private: 
	char * buffer;
public:
	WaveSound(const char * fileName);
	void play(bool asyn = true);
};

