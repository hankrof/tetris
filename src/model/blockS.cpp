#include "blockS.h"
BlockS::BlockS()
{
    DotsLen = 4;
    Dots[0].x = 3;
    Dots[0].y = 0;
    Dots[1].x = 4;
    Dots[1].y = 0;
    Dots[2].x = 4;
    Dots[2].y = -1;
    Dots[3].x = 5;
    Dots[3].y = -1;
}
void BlockS::rotate()
{
	if (!isRotatable())
		return;
	Dots = rotatable;
    rotation_mode = rotation_mode == 1 ? 0 : rotation_mode + 1;
}
bool BlockS::isRotatable()
{
	rotatable = Dots;
	switch (rotation_mode)
	{
	case 0:
		rotatable[2].x--;
		rotatable[3].x--;
		rotatable[3].y += 2;
		if (rotatable[3].y > MAX_EDGE_Y)
			for (int i = 0; i < 4; ++i)
				rotatable[i].y--;
		break;
	case 1:
		rotatable[2].x++;
		rotatable[3].x++;
		rotatable[3].y -= 2;
		if (rotatable[3].x > MAX_EDGE_X)
			for (int i = 0; i < 4; ++i)
				rotatable[i].x--;
		break;
	}
	if (isTouched(rotatable))
		return false;
	return true;
}
