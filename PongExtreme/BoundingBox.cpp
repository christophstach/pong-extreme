#include "stdafx.h"

BoundingBox::BoundingBox()
{
}

void BoundingBox::toConsole()
{
	printf("min(%.3f, %.3f, %.3f), max(%.3f, %.3f, %.3f)\n\n", this->min.x, this->min.y, this->min.z, this->max.x, this->max.y, this->max.z);
}
