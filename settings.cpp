#include "settings.h"
#include "head.h"
#include "body.h"
#include <string.h>

Settings::Settings() :snake_head(1), body(1), head_col(1), body_col(1), food(1), food_col(1) {}

void Settings::set_values(short int one, short int two, short int three, short int four, short int five, short int six)
{
	snake_head = one;
	body = two;
	head_col = three;
	body_col = four;
	food = five;
	food_col = six;
}

inline short int Settings::get_head(){ return snake_head; }
inline short int Settings::get_body(){ return body; }
inline short int Settings::get_head_col(){ return head_col; }
inline short int Settings::get_body_col(){ return body_col; }
inline short int Settings::get_food(){ return food; }
inline short int Settings::get_food_col() { return food_col; }

void Settings::set_attributes(class body& setbody, head& sethead, char* Bcol, char* Hcol, char* Fcol, wchar_t& Ftype)
{
	switch (this->get_body())
	{
	case 1:
		setbody.left_right = L'\x2550';
		setbody.up_down = L'\x2551';
		setbody.up_left = L'\x2557';
		setbody.up_right = L'\x2554';
		setbody.down_left = L'\x255D';
		setbody.down_right = L'\x255A';
		setbody.left_up = L'\x255A';
		setbody.left_down = L'\x2554';
		setbody.right_up = L'\x255D';
		setbody.right_down = L'\x2557';
		break;
	case 2:
		setbody.left_right = L'\x2500';
		setbody.up_down = L'\x2502';
		setbody.up_left = L'\x2510';
		setbody.up_right = L'\x250C';
		setbody.down_left = L'\x2518';
		setbody.down_right = L'\x2514';
		setbody.left_up = L'\x2514';
		setbody.left_down = L'\x250C';
		setbody.right_up = L'\x2518';
		setbody.right_down = L'\x2510';
		break;
	}
	switch (this->get_head())
	{
	case 1:
		sethead.up = L'\x02C4';
		sethead.left = L'\x02C2';
		sethead.right = L'\x02C3';
		sethead.down = L'\x02C5';
		break;
	case 2:
		sethead.up = L'\x25B2';
		sethead.left = L'\x25C4';
		sethead.right = L'\x25BA';
		sethead.down = L'\x25BC';
		break;
	}
	switch (this->get_body_col())
	{
	case 1:strcpy(Bcol, "\033[38;2;255;255;255m"); break;
	case 2:strcpy(Bcol, "\033[38;2;46;197;40m"); break;
	case 3:strcpy(Bcol, "\033[38;2;63;186;178m"); break;
	case 4:strcpy(Bcol, "\033[38;2;214;77;150m"); break;
	case 5:strcpy(Bcol, "\033[38;2;200;205;56m"); break;
	case 6:strcpy(Bcol, "\033[38;2;210;146;62m"); break;
	case 7:strcpy(Bcol, "\033[38;2;215;43;43m"); break;
	}
	switch (this->get_head_col())
	{
	case 1:strcpy(Hcol, "\033[38;2;255;255;255m"); break;
	case 2:strcpy(Hcol, "\033[38;2;46;197;40m"); break;
	case 3:strcpy(Hcol, "\033[38;2;63;186;178m"); break;
	case 4:strcpy(Hcol, "\033[38;2;214;77;150m"); break;
	case 5:strcpy(Hcol, "\033[38;2;200;205;56m"); break;
	case 6:strcpy(Hcol, "\033[38;2;210;146;62m"); break;
	case 7:strcpy(Hcol, "\033[38;2;215;43;43m"); break;
	}
	switch (this->get_food_col())
	{
	case 1:strcpy(Fcol, "\033[38;2;255;255;255m"); break;
	case 2:strcpy(Fcol, "\033[38;2;46;197;40m"); break;
	case 3:strcpy(Fcol, "\033[38;2;210;146;62m"); break;
	case 4:strcpy(Fcol, "\033[38;2;215;43;43m"); break;
	}
	switch (this->get_food())
	{
	case 1:Ftype = L'\x25A0'; break;
	case 2:Ftype = L'\x00D8'; break;
	case 3:Ftype = L'\x25CF'; break;
	case 4:Ftype = L'\x01D1'; break;
	}
}