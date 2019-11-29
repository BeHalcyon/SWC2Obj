#pragma once
#include "based.h"


class ObjWriter
{
public:
	ObjWriter(std::vector<Vertex> point_vector);
	~ObjWriter();

	void searchPath();
	void writeObj(const std::string& file_path);
	void writeObjNormalization(const std::string& file_path, double x_bounding, double y_bounding, double z_bounding);

private:
	std::vector<Path>			paths;
	std::vector<Vertex>			point_vector;
};

