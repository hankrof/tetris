#ifndef __BLOCK_S_H__
#define __BLOCK_S_H__
#include "block.h"
class BlockS final : Block
{
public:
	BlockS();
	void rotate();
	bool isRotatable();
};
#endif
