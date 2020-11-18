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
		//�Ʊ�� tab�����ţ��ֺŶ�������Ч�ķָ����ͳһת�ɿո�
		//Ϊ�˱�����󣬻س����ͻ��з�ҲתΪ�ո񣨷����޷�������У�
		if (c == '\t' || c == ',' || c == ';' || c == '\r' || c == '\n')
			c = ' ';
	}

	line.erase(0, line.find_first_not_of(" "));//ɾ�����׿ո�
	line.erase(line.find_last_not_of(" ") + 1);//ɾ����ĩ�ո�

   //����ע�ͷ�����λ�ã���������ڣ���õ�string::npos
	int n_comment_start = line.find_first_of(comment_str);
	if (n_comment_start != std::string::npos)//��һ������
		line.erase(n_comment_start);         //ɾ��ע��
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
			line_process(line);//�����׺���β�Ķ���ո�, tabȥ�����ע������Ҳȥ��
			if (line.empty()) continue;//lineΪ�������

			//����ʵ��������
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
