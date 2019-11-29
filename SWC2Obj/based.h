#pragma once
#include <vector>

class Vertex
{
public:
	int					current_id;
	int					point_type;
	double				x, y, z;
	double				radius;
	int					previous_id;
	int					index;
	int					degree = 0;
	bool				is_visited = false;
};

class Path
{
public:
	int					path_type;
	std::vector<Vertex> path;
};