#pragma once
#include "head.h"
#include "body.h"
class Settings
{
	short int snake_head;
	short int body;
    short int head_col;
	short int body_col;
	short int food;
	short int food_col;
public:
	inline short int get_head();
	inline short int get_body();
	inline short int get_head_col();
	inline short int get_body_col();
	inline short int get_food();
	inline short int get_food_col();
	void set_values(short int, short int, short int, short int, short int, short int);
	void set_attributes(class body&, head&, char*, char*, char*, wchar_t&);
	Settings();
};

