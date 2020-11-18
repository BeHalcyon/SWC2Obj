#pragma once
#include <vector>

class Block
{
public:
	Block(int x,int y,int z, int b, int p, bool block_state);
	~Block();

	std::vector<unsigned char>& getData();

private:
	int							padding;
	int							x_block_number;
	int							y_block_number;
	int							z_block_number;
	int							block_based;
	bool						block_state;
	std::vector<unsigned char>	data;
};

