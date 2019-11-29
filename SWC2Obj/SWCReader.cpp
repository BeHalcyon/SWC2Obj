#include "SWCReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

SWCReader::SWCReader()
{
}

SWCReader::SWCReader(const std::string& file_name)
			:file_name(file_name)
{

}
void line_process(std::string &line, const std::string comment_str = "#")
{
	for (char &c : line)
	{
		//制表符 tab，逗号，分号都当作有效的分隔符，统一转成空格
		//为了避免错误，回车符和换行符也转为空格（否则无法处理空行）
		if (c == '\t' || c == ',' || c == ';' || c == '\r' || c == '\n')
			c = ' ';
	}

	line.erase(0, line.find_first_not_of(" "));//删除行首空格
	line.erase(line.find_last_not_of(" ") + 1);//删除行末空格

   //查找注释符所在位置，如果不存在，则得到string::npos
	int n_comment_start = line.find_first_of(comment_str);
	if (n_comment_start != std::string::npos)//这一句必须的
		line.erase(n_comment_start);         //删除注释
}

void SWCReader::readSWC(const std::string& file_name)
{
	this->file_name = file_name;

	std::ifstream read_file(file_name);
	if(read_file.is_open())
	{
		std::string line;
		while (std::getline(read_file, line))
		{
			line_process(line);//把行首和行尾的多个空格, tab去掉，把注释文字也去掉
			if (line.empty()) continue;//line为空则继续

			//根据实际需求处理
			std::istringstream iss(line);

			struct Vertex point{};

			iss >> point.current_id >> point.point_type >> point.x >> 
				point.y >> point.z >> point.radius >> point.previous_id;
			
			point_vector.push_back(point);
		}
	}
	else
	{
		std::cout << "Error in opening file : " << file_name << std::endl;
	}

}

SWCReader::~SWCReader()
{
}

std::vector<Vertex>& SWCReader::getPointVector()
{
	return point_vector;
}
