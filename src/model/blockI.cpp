#include "blockI.h"
BlockI::BlockI()
{
	DotsLen = 4;
	for (size_t i = 0; i < DotsLen; ++i)
	{
		Dots[i].x = 4;
		Dots[i].y = -1 + i;
	}
}
void BlockI::rotate()
{
	if (!isRotatable())
		return;
	Dots = rotatable;
	rotation_mode = !rotation_mode;
}
bool BlockI::isRotatable()
{
	int i;
	int xOffset;
	rotatable = Dots;
	switch (rotation_mode)
	{
	case 0:
		for (i = 0; i < 4; ++i)
		{
			rotatable[i].x -= 3 - i;
			rotatable[i].y += 3 - i;
		}
		break;
	case 1:
		for (i = 0; i < 4; ++i)
		{
			rotatable[i].x += 3 - i;
			rotatable[i].y -= 3 - i;
		}
		break;
	}
	if (Dots[0].x < 0)
	{
		xOffset = abs(Dots[0].x);
		for (i = 0; i < 4; ++i)
		{
			rotatable[i].x += xOffset;
		}
	}
	if (isTouched(rotatable))
		return false;
	return true;
}
