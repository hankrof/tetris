#ifndef __BLOCK_Z_H__
#define __BLOCK_Z_H__
#include "block.h"
class BlockZ final : Block
{
public:
	BlockZ();
	void rotate();
	bool isRotatable();
};
#endif
