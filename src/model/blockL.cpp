#include "blockL.h"
BlockL::BlockL()
{
    DotsLen = 4;
    Dots[0].x = 3;
    Dots[0].y = 0;
    Dots[1].x = 4;
    Dots[1].y = 0;
    Dots[2].x = 5;
    Dots[2].y = 0;
    Dots[3].x = 5;
    Dots[3].y = -1;
}
void BlockL::rotate()
{
	if (!isRotatable())
		return;
	Dots = rotatable;
    rotation_mode = rotation_mode == 3 ? 0 : rotation_mode + 1;
}
bool BlockL::isRotatable()
{
	rotatable = Dots;
	switch (rotation_mode)
	{
	case 0:
		rotatable[0].y--;
		rotatable[1].x--;
		rotatable[2].x -= 2;
		rotatable[2].y++;
		rotatable[3].x--;
		rotatable[3].y += 2;
		if (rotatable[3].y> MAX_EDGE_Y)
			for (int i = 0; i < 4; ++i)
				rotatable[i].y--;
		break;
	case 1:
		rotatable[2].x++;
		rotatable[2].y -= 2;
		rotatable[3].x++;
		rotatable[3].y -= 2;
		if (rotatable[3].x > MAX_EDGE_X)
			for (int i = 0; i < 4; ++i)
				rotatable[i].x--;
		break;
	case 2:
		rotatable[1].x++;
		rotatable[1].y++;
		rotatable[3].x--;
		rotatable[3].y++;
		if (rotatable[1].y > MAX_EDGE_Y)
			for (int i = 0; i < 4; ++i)
				rotatable[i].y--;
		break;
	case 3:
		rotatable[0].y++;
		rotatable[1].y--;
		rotatable[2].x++;
		rotatable[2].y++;
		rotatable[3].x++;
		rotatable[3].y--;
		if (rotatable[3].x > MAX_EDGE_X)
			for (int i = 0; i < 4; ++i)
				rotatable[i].x--;
		break;
	}
	if (isTouched(rotatable))
		return false;
	return true;
}
