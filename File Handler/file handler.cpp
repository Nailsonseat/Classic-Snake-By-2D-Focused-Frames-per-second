#include <fstream>
#include "../settings.h"

inline bool file_exist(const char* name)
{
	std::ifstream file(name);
	return file.good();
}

void FileReader(class body& shape_body, class head& shape_head, char* body_colour, char* head_colour, char *food_colour, wchar_t &food_type) {
	Settings data;
	std::fstream file;
	if (!file_exist("Snake settings.dat"))
	{
		file.open("Snake settings.dat", std::ios::binary | std::ios::out);
		file.write((char*)&data, sizeof(data));
		data.set_attributes(shape_body, shape_head, body_colour, head_colour, food_colour, food_type);
		file.close();
	}
	else
	{
		file.open("Snake settings.dat", std::ios::binary | std::ios::in);
		file.read((char*)&data, sizeof(data));
		data.set_attributes(shape_body, shape_head, body_colour, head_colour, food_colour, food_type);
		file.close();
	}
	file.close();
}