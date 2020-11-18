#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../BlockAddressing/json_struct.h"
#include "../SWC2Obj/cmdline.h"


int main(int argc, char* argv[])
{
	struct OutputJsonStruct BlocksJson;
	//struct InputJsonStruct ObjFilesJson;
	if (argc < 2)
	{
		std::cout << "Error: please use command line parameter." << std::endl;
		//return 0;
	}

	cmdline::parser a;
	a.add<std::string>("block", 'b', "input block json files", false, R"(D:\project\science_project\SWC2Obj\x64\Release\workspace\block_array.json)");
	//a.add<std::string>("output", 'o', "output json files", false, R"(D:\project\science_project\SWC2Obj\x64\Release\workspace\block_array.json)");
	//a.add<int>("block_based", 'b', "block length base number", false, 7);
	//a.add<int>("padding", 'p', "block padding", false, 2);
	a.add<int>("x", 'x', "x dimension of raw volume", false, 28452);
	a.add<int>("y", 'y', "y dimension of raw volume", false, 21866);
	a.add<int>("z", 'z', "z dimension of raw volume", false, 4834);

	return 0;
}
