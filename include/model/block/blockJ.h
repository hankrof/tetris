#ifndef __BLOCK_J_H__
#define __BLOCK_J_H__
#include "block.h"
class BlockJ final : Block
{
public:
	BlockJ();
	void rotate();
	bool isRotatable();
};
#endif

