#include "Block.h"


Block::Block(int x, int y, int z, int b, int p, bool block_state) :
	x_block_number(x),
	y_block_number(y),
	z_block_number(z),
	block_based(b),
	padding(p),
	block_state(block_state)
{
	
}

Block::~Block()
{
	data.clear();
}

std::vector<unsigned char>& Block::getData()
{
	//the block is not empty
	if(block_based)
	{
		//TODO



	}
	else
	{
		const auto dimension = static_cast<int>(pow(2, block_based)) - padding;
		data.resize(dimension * dimension * dimension, 0);
	}
	return data;
}
