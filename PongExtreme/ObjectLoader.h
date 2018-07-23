#pragma once

class ObjectLoader
{
public:
	ObjectDefinition * load(const char * path);
	~ObjectLoader();
};