#ifndef __BLOCK_O_H__
#define __BLOCK_O_H__
#include "block.h"
class BlockO final : Block
{
public:
	BlockO();
	void rotate() {} //do nothing
	bool isRotatable() { return true; } //do nothing
};
#endif
