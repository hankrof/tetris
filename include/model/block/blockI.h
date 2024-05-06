#ifndef __BLOCK_I_H__
#define __BLOCK_I_H__
#include "block.h"
class BlockI final : Block
{
public:
	BlockI();
	void rotate();
	bool isRotatable();
};
#endif
