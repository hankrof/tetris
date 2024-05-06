#ifndef __BLOCK_T_H__
#define __BLOCK_T_H__
#include "block.h"
class BlockT final : Block
{
public:
	BlockT();
	void rotate();
	bool isRotatable();
};
#endif
