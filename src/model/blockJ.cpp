#include "blockJ.h"
BlockJ::BlockJ()
{
	DotsLen = 4;
	Dots[0].x = 4;
	Dots[0].y = -1;
	for (size_t i = 1; i < DotsLen; ++i)
	{
		Dots[i].x = 3 + i;
		Dots[i].y = 0;
	}
}
void BlockJ::rotate()
{
	if (!isRotatable())
		return;
	Dots = rotatable;
	rotation_mode = rotation_mode == 3 ? 0 : rotation_mode + 1;
}
bool BlockJ::isRotatable()
{
	rotatable = Dots;
	switch (rotation_mode)
	{
	case 0:
		rotatable[0].x++;
		rotatable[0].y--;
		rotatable[1].y -= 2;
		rotatable[2].x--;
		rotatable[2].y--;
		rotatable[3].x -= 2;
		if (rotatable[1].y < 0)
			for (int i = 0; i < 4; ++i)
				rotatable[i].y++;
		break;
	case 1:
		rotatable[2].x += 2;
		rotatable[2].y--;
		rotatable[3].x += 2;
		rotatable[3].y--;
		if (rotatable[3].x > MAX_EDGE_X) //fix location
			for (int i = 0; i < 4; ++i)
				rotatable[i].x--;
		break;
	case 2:
		rotatable[0].x++;
		rotatable[0].y += 2;
		rotatable[1].x++;
		rotatable[1].y += 2;
		if (rotatable[0].y > MAX_EDGE_Y) //fix location
			for (int i = 0; i < 4; ++i)
				rotatable[i].y--;
		break;
	case 3:
		rotatable[0].x -= 2;
		rotatable[0].y--;
		rotatable[1].x--;
		rotatable[2].x--;
		rotatable[2].y += 2;
		rotatable[3].y++;
		if (rotatable[0].x < 0)//fix location
			for (int i = 0; i < 4; ++i)
				rotatable[i].x++;
		break;
	}
	if (isTouched(rotatable))
		return false;
	return true;
}
