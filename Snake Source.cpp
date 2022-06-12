#include "Headers/Nailsonseat.h"
#include "File Handler/file handler.cpp"
#include "settings.h"
#include "head.h"
#include "body.h"
#include <vector>
#include <iostream>

using namespace std;


COORD food_generator(short int notouch1, COORD notouch2, vector <COORD> notouch3)
{
	int temp(0);
	bool flag(true);
	srand(int(time(0)));
	COORD food;
	if (!notouch1) 
	{
		do
		{
			food.X = rand() % 79;
			food.Y = rand() % 24;
			if (food.X >= 71 && food.X <= 79)continue;
		} while (food.X > 43 && food.X < 37 && food.Y < 15 && food.Y > 9 && food.X <= 0 && food.X > 79 && food.Y <= 0 && food.Y > 24);
	}
	else if (notouch1)
	{
		do
		{
			food.X = rand() % 79;
			food.Y = rand() % 24;
			if (food.X >= 71 && food.X <= 79)continue;
			if (food.X == notouch2.X && food.Y == notouch2.Y)continue;
			for (auto temp = notouch3.begin(); temp != notouch3.end(); temp++)
			{
				if (temp->X == food.X && temp->Y == food.Y)flag = false;
				else flag=true;
			}
		} while (food.X <= 0 && food.X > 79 && food.Y <= 0 && food.Y > 24 && !flag);
	}
	return food;
}
short int menu()
{
	short int input(0), output(0);
	COORD select = { 0,0 };
	maskcursor(true);
	gotoxy(0, 24);
	cout << "v5.0";
	gotoxy(56, 24);
	cout << "Made by - Aadarsh Verma";
	gotoxy(27, 0);
	cout << R"( _____             _         )";
	gotoxy(27, 1);
	cout << R"(/  ___|           | |        )";
	gotoxy(27, 2);
	cout << R"(\ `--. _ __   __ _| | _____  )";
	gotoxy(27, 3);
	cout << R"( `--. \ '_ \ / _` | |/ / _ \ )";
	gotoxy(27, 4);
	cout << R"(/\__/ / | | | (_| |   <  __/ )";
	gotoxy(27, 5);
	cout << R"(\____/|_| |_|\__,_|_|\_\___| )" << endl;
	cout << " Start" << endl;
	cout << " Options" << endl;
	cout << " Exit";
	gotoxy(10, 6);
	cout << "<--";
	gotoxy(10, 6);
	while (!(input == 13))
	{
		switch ((input = _getch()))
		{
		case 72:getxy(select.X, select.Y);
			maskcursor(true);
			if (select.Y != 6)
			{
				cout << "   ";
				gotoxy(10, select.Y - 1);
				cout << "<--";
				gotoxy(10, select.Y - 1);
			}
			getxy(select.X, select.Y);
			break;
		case 80:getxy(select.X, select.Y);
			maskcursor(true);
			if (select.Y != 8)
			{
				cout << "   ";
				gotoxy(10, select.Y + 1);
				cout << "<--";
				gotoxy(10, select.Y + 1);
			}
			getxy(select.X, select.Y);
			break;
		default:if (input == 13) output = select.Y;
			break;
		}
	}
	system("cls");
	return output;
}
void delay(short int direction)
{
	switch (direction)
	{
	case 72:
	case 80:Sleep(220); break;
	case 75:
	case 77:Sleep(80); break;
	}
}
COORD snake_head(short int pos, COORD snake, head shape, char* colour)
{
	COORD curr = { 0,0 };
	cout << colour;
	mode_u16();
	switch (pos)
	{
	case 72:go_up();
		getxy(curr.X, curr.Y);
		wcout <<shape.up;
		gotoxy(snake.X, snake.Y);
		wcout << L'\x00A0';
		gotoxy(curr.X, curr.Y);
		break;
	case 75:go_left();
		getxy(curr.X, curr.Y);
		wcout <<shape.left;
		gotoxy(snake.X, snake.Y);
		wcout << L'\x00A0';
		gotoxy(curr.X, curr.Y);
		break;
	case 80:go_down();
		getxy(curr.X, curr.Y);
		wcout <<shape.down;
		gotoxy(snake.X, snake.Y);
		wcout << L'\x00A0';
		gotoxy(curr.X, curr.Y);
		break;
	case 77:go_right();
		getxy(curr.X, curr.Y);
		wcout <<shape.right;
		gotoxy(snake.X, snake.Y);
		wcout << L'\x00A0';
		gotoxy(curr.X, curr.Y);
		break;
	}
	mode_ascii();
	cout << "\033[0m";
	return curr;
}
void options(Settings& save)
{
	COORD last = { -1,-1 };
	short int column = 1;
	fstream file;
	short int input(0);
	char H_col[20];
	char B_col[20];
	char F_col[20];
	short int previous[6] = { save.get_head(), save.get_body(),save.get_head_col(),save.get_body_col(),save.get_food(),save.get_food_col() };
reset:
	switch (save.get_head_col())
	{
	case 1:strcpy(H_col, "\033[38;2;255;255;255m"); break;
	case 2:strcpy(H_col, "\033[38;2;46;197;40m"); break;
	case 3:strcpy(H_col, "\033[38;2;63;186;178m"); break;
	case 4:strcpy(H_col, "\033[38;2;214;77;150m"); break;
	case 5:strcpy(H_col, "\033[38;2;200;205;56m"); break;
	case 6:strcpy(H_col, "\033[38;2;210;146;62m"); break;
	case 7:strcpy(H_col, "\033[38;2;215;43;43m"); break;
	}
	switch (save.get_body_col())
	{
	case 1:strcpy(B_col, "\033[38;2;255;255;255m"); break;
	case 2:strcpy(B_col, "\033[38;2;46;197;40m"); break;
	case 3:strcpy(B_col, "\033[38;2;63;186;178m"); break;
	case 4:strcpy(B_col, "\033[38;2;214;77;150m"); break;
	case 5:strcpy(B_col, "\033[38;2;200;205;56m"); break;
	case 6:strcpy(B_col, "\033[38;2;210;146;62m"); break;
	case 7:strcpy(B_col, "\033[38;2;215;43;43m"); break;
	}
	switch (save.get_food_col())
	{
	case 1:strcpy(F_col, "\033[38;2;255;255;255m"); break;
	case 2:strcpy(F_col, "\033[38;2;46;197;40m"); break;
	case 3:strcpy(F_col, "\033[38;2;210;146;62m"); break;
	case 4:strcpy(F_col, "\033[38;2;215;43;43m"); break;
	}
	system("cls");
	gotoxy(38, 0);
	cout << "Options";
	gotoxy(8, 3);

	cout << "Snake head";
	mode_u16();
	gotoxy(10, 6); if (save.get_head() == 1)wcout << L'\x25A0'; else wcout << L'\x25A1';
	gotoxy(12, 6); mode_ascii(); cout << H_col; mode_u16();
	wcout << L"\x02C4\x02C3\x02C2\x02C5";
	mode_ascii(); cout << "\033[0m"; mode_u16();
	gotoxy(10, 10); if (save.get_head() == 2)wcout << L'\x25A0'; else wcout << L'\x25A1';
	gotoxy(12, 10); mode_ascii(); cout << H_col; mode_u16();
	wcout << L"\x25B2\x25BA\x25C4\x25BC";
	mode_ascii(); cout << "\033[0m";
	gotoxy(28, 3);

	cout << "Body";
	mode_u16();
	gotoxy(28, 6); if (save.get_body() == 1)wcout << L'\x25A0'; else wcout << L'\x25A1';
	gotoxy(30, 6); mode_ascii(); cout << B_col; mode_u16();
	wcout << L"\x2550\x255D"; go_left(); go_up(); wcout << L"\x2554\x2550";
	mode_ascii(); cout << "\033[0m"; mode_u16();
	gotoxy(28, 10); if (save.get_body() == 2)wcout << L'\x25A0'; else wcout << L'\x25A1';
	gotoxy(30, 10); mode_ascii(); cout << B_col; mode_u16();
	wcout << L"\x2500\x2518"; go_left(); go_up(); wcout << L"\x250C\x2500";
	mode_ascii(); cout << "\033[0m";
	gotoxy(41, 3);

	cout << "Head colour";
	gotoxy(43, 6); mode_u16(); if (save.get_head_col() == 1)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 6);
	cout << "\033[38;2;255;255;255m" << "White" << "\033[0m";
	gotoxy(43, 8); mode_u16(); if (save.get_head_col() == 2)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 8);
	cout << "\033[38;2;46;197;40m" << "Green" << "\033[0m";
	gotoxy(43, 10); mode_u16(); if (save.get_head_col() == 3)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 10);
	cout << "\033[38;2;63;186;178m" << "Blue" << "\033[0m";
	gotoxy(43, 12); mode_u16(); if (save.get_head_col() == 4)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 12);
	cout << "\033[38;2;214;77;150m" << "Pink" << "\033[0m";
	gotoxy(43, 14); mode_u16(); if (save.get_head_col() == 5)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 14);
	cout << "\033[38;2;200;205;56m" << "Yellow" << "\033[0m";
	gotoxy(43, 16); mode_u16(); if (save.get_head_col() == 6)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 16);
	cout << "\033[38;2;210;146;62m" << "Orange" << "\033[0m";
	gotoxy(43, 18); mode_u16(); if (save.get_head_col() == 7)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 18);
	cout << "\033[38;2;215;43;43m" << "Red" << "\033[0m";
	gotoxy(62, 3);

	cout << "Body colour";
	gotoxy(64, 6); mode_u16(); if (save.get_body_col() == 1)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 6);
	cout << "\033[38;2;255;255;255m" << "White" << "\033[0m";
	gotoxy(64, 8); mode_u16(); if (save.get_body_col() == 2)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 8);
	cout << "\033[38;2;46;197;40m" << "Green" << "\033[0m";
	gotoxy(64, 10); mode_u16(); if (save.get_body_col() == 3)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 10);
	cout << "\033[38;2;63;186;178m" << "Blue" << "\033[0m";
	gotoxy(64, 12); mode_u16(); if (save.get_body_col() == 4)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 12);
	cout << "\033[38;2;214;77;150m" << "Pink" << "\033[0m";
	gotoxy(64, 14); mode_u16(); if (save.get_body_col() == 5)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 14);
	cout << "\033[38;2;200;205;56m" << "Yellow" << "\033[0m";
	gotoxy(64, 16); mode_u16(); if (save.get_body_col() == 6)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 16);
	cout << "\033[38;2;210;146;62m" << "Orange" << "\033[0m";
	gotoxy(64, 18); mode_u16(); if (save.get_body_col() == 7)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 18);
	cout << "\033[38;2;215;43;43m" << "Red" << "\033[0m";
	gotoxy(31, 23); cout << "Save";
	gotoxy(42, 23); cout << "Cancel";
	gotoxy(10, 13);

	cout << "Foods";
	mode_u16();
	gotoxy(13, 15); mode_ascii(); cout << F_col; mode_u16();
	wcout << L'\x25A0';
	mode_ascii(); cout << "\033[0m"; mode_u16();
	gotoxy(11, 15); if (save.get_food() == 1)wcout << L'\x25A0'; else wcout << L'\x25A1';
	gotoxy(13, 17); mode_ascii(); cout << F_col; mode_u16();
	wcout << L'\x00D8';
	mode_ascii(); cout << "\033[0m"; mode_u16();
	gotoxy(11, 17); if (save.get_food() == 2)wcout << L'\x25A0'; else wcout << L'\x25A1';
	gotoxy(13, 19); mode_ascii(); cout << F_col; mode_u16();
	wcout << L'\x25CF';
	mode_ascii(); cout << "\033[0m"; mode_u16();
	gotoxy(11, 19); if (save.get_food() == 3)wcout << L'\x25A0'; else wcout << L'\x25A1';
	gotoxy(13, 21); mode_ascii(); cout << F_col; mode_u16();
	wcout << L'\x01D1';
	mode_ascii(); cout << "\033[0m"; mode_u16();
	gotoxy(11, 21); if (save.get_food() == 4)wcout << L'\x25A0'; else wcout << L'\x25A1';
	mode_ascii();
	gotoxy(25, 13);

	cout << "Food colour";
	gotoxy(29, 15); cout << "\033[38;2;255;255;255m" << "White" << "\033[0m";
	gotoxy(27, 15); mode_u16(); if (save.get_food_col() == 1)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(29, 17); cout << "\033[38;2;46;197;40m" << "Green" << "\033[0m";
	gotoxy(27, 17); mode_u16(); if (save.get_food_col() == 2)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(29, 19); cout << "\033[38;2;210;146;62m" << "Orange" << "\033[0m";
	gotoxy(27, 19); mode_u16(); if (save.get_food_col() == 3)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();
	gotoxy(29, 21); cout << "\033[38;2;215;43;43m" << "Red" << "\033[0m";
	gotoxy(27, 21); mode_u16(); if (save.get_food_col() == 4)wcout << L'\x25A0'; else wcout << L'\x25A1'; mode_ascii();

	if (last.X == -1 && last.Y == -1) { gotoxy(5, 6); cout << "-->"; }
	else { gotoxy(last.X, last.Y); cout << "-->"; }
	do
	{
		input = _getch();
		if (input == 224)input = _getch();
		switch (input)
		{
		case 72:
			getxy(last.X, last.Y);
			if (last.Y == 6)break;
			gotoxy(last.X - 3, last.Y); cout << "   ";
			if (column == 1 && last.Y == 23)gotoxy(7, 21);
			else if (column == 2 && last.Y == 23)gotoxy(23, 21);
			else if (column == 3 && last.Y == 23)gotoxy(38, 16);
			else if (column == 4 && last.Y == 23)gotoxy(59, 16);
			else if (column <= 2 && last.Y <= 10)gotoxy(last.X - 3, last.Y - 4);
			else if (column == 1 && last.Y == 15)gotoxy(last.X - 5, 10);
			else if (column == 2 && last.Y == 15)gotoxy(last.X - 3, 10);
			else if (column <= 2 && last.Y > 15)gotoxy(last.X - 3, last.Y - 2);
			else if (column >= 3)gotoxy(last.X - 3, last.Y - 2);
			cout << "-->";
			getxy(last.X, last.Y);
			break;
		case 80:
			getxy(last.X, last.Y);
			/*if (last.Y == 10 && column<=2)break;
			else if (last.Y == 16)break;*/
			if (last.Y == 23)break;
			gotoxy(last.X - 3, last.Y); cout << "   ";
			if (last.Y == 10 && column == 1)gotoxy(7, last.Y + 5);
			else if (last.Y == 10 && column == 2)gotoxy(23, last.Y + 5);
			else if (column <= 2 && last.Y == 21)gotoxy(27, 23);
			else if (last.Y == 18 && column >= 3)gotoxy(38, 23);
			else if (column <= 2 && last.Y <= 10)gotoxy(last.X - 3, last.Y + 4);
			else if (column <= 2 && last.Y >= 15)gotoxy(last.X - 3, last.Y + 2);
			else if (column >= 3)gotoxy(last.X - 3, last.Y + 2);
			cout << "-->";
			getxy(last.X, last.Y);
			break;
		case 77:
			if (column == 4 && last.Y != 23)break;
			else if (last.X == 41 && last.Y == 23)break;
			else if (column == 2 && last.Y > 20 && last.Y != 23)break;
			getxy(last.X, last.Y);
			gotoxy(last.X - 3, last.Y); cout << "   ";
			if (last.X == 30 && last.Y == 23)gotoxy(38, 23);
			else if (column == 1)gotoxy(23, last.Y);
			else if (column == 2 && last.Y >= 15 && last.Y <= 19)gotoxy(38, last.Y - 1);
			else if (column == 2)gotoxy(38, last.Y);
			else if (column == 3)gotoxy(59, last.Y);
			cout << "-->";
			if(last.Y!=23)column++;
			getxy(last.X, last.Y);
			break;
		case 75:
			if (column == 1 && last.Y != 23)break;
			else if (last.X == 30 && last.Y == 23)break;
			getxy(last.X, last.Y);
			gotoxy(last.X - 3, last.Y); cout << "   ";
			if (last.Y == 23 && last.X == 41)gotoxy(27, 23);
			else if (column == 4)gotoxy(38, last.Y);
			else if (column == 3 && last.Y == 8)gotoxy(23, last.Y - 2);
			else if (column == 3 && last.Y == 6)gotoxy(23, last.Y);
			else if (column == 3 && (last.Y == 10 || last.Y == 12))gotoxy(23, 10);
			else if (column == 3 && last.Y >= 14)gotoxy(23, last.Y + 1);
			else if (column == 2 && last.Y <= 10)gotoxy(5, last.Y);
			else if (column == 2 && last.Y >= 15)gotoxy(7, last.Y);
			cout << "-->";
			if (last.Y != 23)column--;
			getxy(last.X, last.Y);
			break;
		}
	} while (input != 13 && input != 27);
	if ((last.X == 41 && last.Y == 23) || input == 27) { system("cls"); save.set_values(previous[0], previous[1], previous[2], previous[3], previous[4], previous[5]); return; }
	switch (column)
	{
	case 1:if (last.Y == 6)save.set_values(1, save.get_body(), save.get_head_col(), save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 10)save.set_values(2, save.get_body(), save.get_head_col(), save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 15)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), save.get_body_col(), 1, save.get_food_col());
		  else if (last.Y == 17)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), save.get_body_col(), 2, save.get_food_col());
		  else if (last.Y == 19)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), save.get_body_col(), 3, save.get_food_col());
		  else if (last.Y == 21)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), save.get_body_col(), 4, save.get_food_col());
		break;
	case 2:if (last.Y == 6)save.set_values(save.get_head(), 1, save.get_head_col(), save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 10)save.set_values(save.get_head(), 2, save.get_head_col(), save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 15)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), save.get_body_col(), save.get_food(), 1);
		  else if (last.Y == 17)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), save.get_body_col(), save.get_food(), 2);
		  else if (last.Y == 19)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), save.get_body_col(), save.get_food(), 3);
		  else if (last.Y == 21)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), save.get_body_col(), save.get_food(), 4);
		break;
	case 3:if(last.Y==6)save.set_values(save.get_head(), save.get_body(), 1, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if(last.Y==8)save.set_values(save.get_head(), save.get_body(), 2, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if(last.Y==10)save.set_values(save.get_head(), save.get_body(), 3, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if(last.Y==12)save.set_values(save.get_head(), save.get_body(), 4, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if(last.Y==14)save.set_values(save.get_head(), save.get_body(), 5, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if(last.Y==16)save.set_values(save.get_head(), save.get_body(), 6, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if(last.Y==18)save.set_values(save.get_head(), save.get_body(), 7, save.get_body_col(), save.get_food(), save.get_food_col());
		break;
	case 4:if (last.Y == 6)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), 1, save.get_food(), save.get_food_col());
		  else if (last.Y == 8)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), 2, save.get_food(), save.get_food_col());
		  else if (last.Y == 10)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), 3, save.get_food(), save.get_food_col());
		  else if (last.Y == 12)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), 4, save.get_food(), save.get_food_col());
		  else if (last.Y == 14)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), 5, save.get_food(), save.get_food_col());
		  else if (last.Y == 16)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), 6, save.get_food(), save.get_food_col());
		  else if (last.Y == 18)save.set_values(save.get_head(), save.get_body(), save.get_head_col(), 7, save.get_food(), save.get_food_col());
		break;
	}
	if (last.X == 30 && last.Y == 23)
	{
		file.open("Snake settings.dat", ios::binary | ios::out);
		file.write((char*)&save, sizeof(save));
		file.close();
	}
	else { last.X -= 3; goto reset; }
	system("cls");
}
int main()
{
	fontsize(0, 30);
	MoveWindow(7,0);
	short int input(0), score(0), previous(0);
	COORD food = { 0,0 }, head = { 40,12 };
	vector <COORD> body;
	class body shape_body;
	class head shape_head;
	char body_colour[20];
	char head_colour[20];
	char food_colour[20];
	wchar_t food_type(NULL);

	bool bound_check(true);
	
	FileReader(shape_body, shape_head, body_colour, head_colour, food_colour, food_type);


menu:short int ans = menu();
	switch (ans)
	{
	case 6:break;
	case 7:
		Settings data;
		options(data);
		data.set_attributes(shape_body, shape_head, body_colour, head_colour,food_colour,food_type);
		goto menu;
		break;
	case 8:cout << "Game Exited";
		return 0;
	}
	begin:
	gotoxy(27, 12);
	cout << "Press any cursor key to start";
	do { input = _getch(); if (input == 224)input = _getch(); } 
	while (input != 72 && input != 80 && input != 75 && input != 77);
	system("cls");
	food = food_generator(score,head,body);
	gotoxy(40, 12);
	do
	{
		if (previous != 0) 
		{
			input = _getch();
			if (input == 224)input = _getch();
		}
		if (input != 72 && input != 80 && input != 75 && input != 77 && input != 27)input = previous;
		while (!_kbhit())
		{
			maskcursor(true);
			if (input == 27) break;
			if (body.size() >= 2) 
			{
				for (int i = short int(body.size()) - 2; i >= 0; i--)
				{
					if (head.X == body[i].X && head.Y == body[i].Y)
					{
						gotoxy(35, 12);
						cout << "Game Over";
						gotoxy(29, 13);
						cout << "Press Enter to Restart";
					over:input = _getch();
						switch (input)
						{
						case 27:system("cls"); input = 0; previous = 0; head = { 40,12 }; score = 0; body.clear(); goto menu;
						case 13:system("cls"); input = 0; previous = 0; head = { 40,12 }; score = 0; body.clear(); goto begin;
						default:goto over;
						}
					}
				}
			}
			if (previous == 80 && input == 72 && score)input = 80;
			else if (previous == 72 && input == 80 && score)input = 72;
			else if (previous == 75 && input == 77 && score)input = 75;
			else if (previous == 77 && input == 75 && score)input = 77;
			if (head.X == 79 && input == 77) { if (!score) { gotoxy(head.X, head.Y); cout << ' '; }gotoxy(0, head.Y); bound_check = false; }
			if (head.X == 0 && input == 75) { if (!score) { gotoxy(head.X, head.Y); cout << ' '; } gotoxy(79, head.Y); bound_check = false; }
			if (head.Y == 0 && input == 72) { if (!score) { gotoxy(head.X, head.Y); cout << ' '; } gotoxy(head.X, 24); bound_check = false; }
			if (head.Y == 24 && input == 80) { if (!score) { gotoxy(head.X, head.Y); cout << ' '; } gotoxy(head.X, 0); bound_check = false; }
			if (body.size() == score + 2)body.erase(body.begin());
			body.shrink_to_fit();
			getxy(head.X, head.Y);
			gotoxy(food.X, food.Y);
			cout << food_colour;
			mode_u16();
			wcout <<food_type;
			mode_ascii();
			cout << "\033[0m";
			gotoxy(71, 0);
			cout << "Score-" << score;
			gotoxy(head.X, head.Y);
			delay(input);
			if(bound_check)head = snake_head(input, head, shape_head, head_colour);
			bound_check = true;
			body.push_back(head);
			if (score)
			{
				cout << body_colour;
				gotoxy(body[body.size() - 2].X, body[body.size() - 2].Y);
				mode_u16();
				switch (input)
				{
				case 72:if (body[body.size() - 2].X - body[body.size() - 3].X == 1)wcout << shape_body.right_up;
					   else if (body[body.size() - 2].X - body[body.size() - 3].X == -1)wcout << shape_body.left_up;
					   else wcout << shape_body.up_down; break;
				case 80:if (body[body.size() - 2].X - body[body.size() - 3].X == 1)wcout << shape_body.right_down;
					   else if (body[body.size() - 2].X - body[body.size() - 3].X == -1)wcout << shape_body.left_down;
					   else wcout << shape_body.up_down; break;
				case 75:if (body[body.size() - 2].Y - body[body.size() - 3].Y == 1)wcout << shape_body.down_left;
					   else if (body[body.size() - 2].Y - body[body.size() - 3].Y == -1)wcout << shape_body.up_left;
					   else wcout << shape_body.left_right; break;
				case 77:if (body[body.size() - 2].Y - body[body.size() - 3].Y == 1)wcout << shape_body.down_right;
					   else if (body[body.size() - 2].Y - body[body.size() - 3].Y == -1)wcout << shape_body.up_right;
					   else wcout << shape_body.left_right; break;
				}
				mode_ascii();
				cout << "\033[0m";
				gotoxy(body[body.size() - score - 2].X, body[body.size() - score - 2].Y); cout << ' ';
				gotoxy(head.X, head.Y);
			}
			if (head.X == food.X && head.Y == food.Y)
			{
				food = food_generator(score,head,body);
				score++;
			}
			previous = input;
		}
	} while (input != 27);
	input = 0;
	previous = 0;
	body.clear();
	score = 0;
	head = { 40,12 };
	system("cls");
	goto menu;
}