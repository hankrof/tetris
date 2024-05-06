#ifndef __BLOCK_L_H__
#define __BLOCK_L_H__
#include "block.h"
class BlockL final : Block
{
public:
	BlockL();
	void rotate();
	bool isRotatable();
};
#endif
