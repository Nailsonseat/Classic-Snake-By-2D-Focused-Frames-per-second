#include "menu.h"
#include "Headers/Nailsonseat.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

short int menu()
{
	short int input(0), output(0);
	COORD select = { 0,0 };
	maskcursor(true);
	gotoxy(0, 24);
	std::cout << "v5.0";
	gotoxy(56, 24);
	std::cout << "Made by - Aadarsh Verma";
	gotoxy(27, 0);
	std::cout << R"( _____             _         )";
	gotoxy(27, 1);
	std::cout << R"(/  ___|           | |        )";
	gotoxy(27, 2);
	std::cout << R"(\ `--. _ __   __ _| | _____  )";
	gotoxy(27, 3);
	std::cout << R"( `--. \ '_ \ / _` | |/ / _ \ )";
	gotoxy(27, 4);
	std::cout << R"(/\__/ / | | | (_| |   <  __/ )";
	gotoxy(27, 5);
	std::cout << R"(\____/|_| |_|\__,_|_|\_\___| )" << std::endl;
	std::cout << " Start" << std::endl;
	std::cout << " Options" << std::endl;
	std::cout << " Exit";
	gotoxy(10, 6);
	std::cout << "<--";
	gotoxy(10, 6);
	while (!(input == 13))
	{
		switch ((input = _getch()))
		{
		case 72:getxy(select.X, select.Y);
			maskcursor(true);
			if (select.Y != 6)
			{
				std::cout << "   ";
				gotoxy(10, select.Y - 1);
				std::cout << "<--";
				gotoxy(10, select.Y - 1);
			}
			getxy(select.X, select.Y);
			break;
		case 80:getxy(select.X, select.Y);
			maskcursor(true);
			if (select.Y != 8)
			{
				std::cout << "   ";
				gotoxy(10, select.Y + 1);
				std::cout << "<--";
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