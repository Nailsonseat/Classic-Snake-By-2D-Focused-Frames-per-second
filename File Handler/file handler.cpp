#include <fstream>
#include "../settings.h"
#include "../settings.cpp"

//using namespace std;
inline bool file_exist(const char* name)
{
	std::ifstream file(name);
	return file.good();
}

void file_reader(settings &data) {
	std::fstream file;
	if (!file_exist("Snake settings.dat"))
	{
		file.open("Snake settings.dat", std::ios::binary | std::ios::out);
		file.write((char*)&data, sizeof(data));
		set_attributes(data, shape_body, shape_head, body_colour, head_colour, food_colour, food_type);
		file.close();
	}
	else
	{
		file.open("Snake settings.dat", std::ios::binary | std::ios::in);
		file.read((char*)&data, sizeof(data));
		set_attributes(data, shape_body, shape_head, body_colour, head_colour, food_colour, food_type);
		file.close();
	}
}