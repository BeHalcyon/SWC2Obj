#include "ObjWriter.h"
#include <map>
#include <iostream>
#include <fstream>

ObjWriter::ObjWriter(std::vector<Vertex> point_vec):point_vector(point_vec)
{
	for (auto i = 0; i < point_vector.size(); i++)
	{
		point_vector[i].index = i + 1;
		point_vector[i].degree = 0;
	}

}

ObjWriter::~ObjWriter()
{
}

void ObjWriter::searchPath()
{
	//1. 获取所有叶子结点
	std::vector<int> leaf_nodes;
	std::map<int, int> vertex_hash;
	for (auto i = 0; i < point_vector.size(); i++)
	{
		vertex_hash[point_vector[i].current_id] = i;
	}
	for(auto& i: point_vector)
	{
		if(i.previous_id!=-1)
		{
			point_vector[vertex_hash[i.previous_id]].degree++;
		}
	}
	for (auto& i : point_vector)
	{
		if(i.degree==0 && i.previous_id!=-1)
		{
			leaf_nodes.push_back(i.current_id);
		}
	}
	//2. 从叶子结点出发，向前查找路径
	auto path_index = 0;
	for(auto & left_node : leaf_nodes)
	{
		Path path;
		std::vector<Vertex> vertices;
		// auto & cur_vertex = point_vector[vertex_hash[left_node]];
		// cur_vertex.is_visited = true;
		// vertices.push_back(cur_vertex);

		auto cur_idx = left_node;
		while(cur_idx!=-1 && !point_vector[vertex_hash[cur_idx]].is_visited)
		{
			auto &buf_vertex = point_vector[vertex_hash[cur_idx]];
			buf_vertex.is_visited = true;
			vertices.push_back(buf_vertex);
			cur_idx = buf_vertex.previous_id;
		}

		if(cur_idx!=-1)
		{
			vertices.push_back(point_vector[vertex_hash[cur_idx]]);
		}

		path.path = vertices;
		path.path_type = path_index;
		path_index++;
		paths.push_back(path);
	}

	// auto sum = 0;
	// for(auto & path: paths)
	// {
	// 	sum += path.path.size();
	// }
	// std::cout << "Sum :\t" << sum << std::endl;
}

void ObjWriter::writeObj(const std::string & file_path)
{

	std::ofstream write_file(file_path);

	write_file << "#vertex_num " << static_cast<unsigned int>(point_vector.size()) << std::endl;

	for(auto & vertex: point_vector)
	{
		write_file << "v " << vertex.x <<" "<< vertex.y << " " << vertex.z << std::endl;
	}

	for(auto j=0;j< paths.size();j++)
	{
		auto & path = paths[j].path;
		write_file << "g" << " path" << paths[j].path_type << std::endl;
		for (int i = path.size() - 1; i >= 1; i--)
		{
			write_file << "l"<< " " << path[i].index<< " " << path[i-1].index<< std::endl;
		}
	}
	write_file.close();
}


void ObjWriter::writeObjNormalization(const std::string & file_path, const double x_bounding, const double y_bounding, const double z_bounding)
{

	std::ofstream write_file(file_path);

	write_file << "#vertex_num " << static_cast<unsigned int>(point_vector.size()) << std::endl;

	for (auto & vertex : point_vector)
	{
		write_file << "v " << vertex.x/x_bounding << " " << vertex.y / y_bounding << " " << vertex.z / z_bounding << std::endl;
	}

	for (auto j = 0; j < paths.size(); j++)
	{
		auto & path = paths[j].path;
		write_file << "g" << " path" << paths[j].path_type << std::endl;
		for (int i = path.size() - 1; i >= 1; i--)
		{
			write_file << "l" << " " << path[i].index << " " << path[i - 1].index << std::endl;
		}
	}
	write_file.close();
}