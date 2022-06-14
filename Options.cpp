#include "Headers/Nailsonseat.h"
#include "options.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>

void options(Settings& save)
{
	COORD last = { -1,-1 };
	short int column = 1;
	std::fstream file;
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
	std::cout << "Options";
	gotoxy(8, 3);

	std::cout << "Snake head";
	mode_u16();
	gotoxy(10, 6); if (save.get_head() == 1)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1';
	gotoxy(12, 6); mode_ascii(); std::cout << H_col; mode_u16();
	std::wcout << L"\x02C4\x02C3\x02C2\x02C5";
	mode_ascii(); std::cout << "\033[0m"; mode_u16();
	gotoxy(10, 10); if (save.get_head() == 2)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1';
	gotoxy(12, 10); mode_ascii(); std::cout << H_col; mode_u16();
	std::wcout << L"\x25B2\x25BA\x25C4\x25BC";
	mode_ascii(); std::cout << "\033[0m";
	gotoxy(28, 3);

	std::cout << "Body";
	mode_u16();
	gotoxy(28, 6); if (save.get_body() == 1)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1';
	gotoxy(30, 6); mode_ascii(); std::cout << B_col; mode_u16();
	std::wcout << L"\x2550\x255D"; go_left(); go_up(); std::wcout << L"\x2554\x2550";
	mode_ascii(); std::cout << "\033[0m"; mode_u16();
	gotoxy(28, 10); if (save.get_body() == 2)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1';
	gotoxy(30, 10); mode_ascii(); std::cout << B_col; mode_u16();
	std::wcout << L"\x2500\x2518"; go_left(); go_up(); std::wcout << L"\x250C\x2500";
	mode_ascii(); std::cout << "\033[0m";
	gotoxy(41, 3);

	std::cout << "Head colour";
	gotoxy(43, 6); mode_u16(); if (save.get_head_col() == 1)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 6);
	std::cout << "\033[38;2;255;255;255m" << "White" << "\033[0m";
	gotoxy(43, 8); mode_u16(); if (save.get_head_col() == 2)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 8);
	std::cout << "\033[38;2;46;197;40m" << "Green" << "\033[0m";
	gotoxy(43, 10); mode_u16(); if (save.get_head_col() == 3)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 10);
	std::cout << "\033[38;2;63;186;178m" << "Blue" << "\033[0m";
	gotoxy(43, 12); mode_u16(); if (save.get_head_col() == 4)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 12);
	std::cout << "\033[38;2;214;77;150m" << "Pink" << "\033[0m";
	gotoxy(43, 14); mode_u16(); if (save.get_head_col() == 5)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 14);
	std::cout << "\033[38;2;200;205;56m" << "Yellow" << "\033[0m";
	gotoxy(43, 16); mode_u16(); if (save.get_head_col() == 6)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 16);
	std::cout << "\033[38;2;210;146;62m" << "Orange" << "\033[0m";
	gotoxy(43, 18); mode_u16(); if (save.get_head_col() == 7)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(45, 18);
	std::cout << "\033[38;2;215;43;43m" << "Red" << "\033[0m";
	gotoxy(62, 3);

	std::cout << "Body colour";
	gotoxy(64, 6); mode_u16(); if (save.get_body_col() == 1)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 6);
	std::cout << "\033[38;2;255;255;255m" << "White" << "\033[0m";
	gotoxy(64, 8); mode_u16(); if (save.get_body_col() == 2)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 8);
	std::cout << "\033[38;2;46;197;40m" << "Green" << "\033[0m";
	gotoxy(64, 10); mode_u16(); if (save.get_body_col() == 3)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 10);
	std::cout << "\033[38;2;63;186;178m" << "Blue" << "\033[0m";
	gotoxy(64, 12); mode_u16(); if (save.get_body_col() == 4)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 12);
	std::cout << "\033[38;2;214;77;150m" << "Pink" << "\033[0m";
	gotoxy(64, 14); mode_u16(); if (save.get_body_col() == 5)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 14);
	std::cout << "\033[38;2;200;205;56m" << "Yellow" << "\033[0m";
	gotoxy(64, 16); mode_u16(); if (save.get_body_col() == 6)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 16);
	std::cout << "\033[38;2;210;146;62m" << "Orange" << "\033[0m";
	gotoxy(64, 18); mode_u16(); if (save.get_body_col() == 7)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(66, 18);
	std::cout << "\033[38;2;215;43;43m" << "Red" << "\033[0m";
	gotoxy(31, 23); std::cout << "Save";
	gotoxy(42, 23); std::cout << "Cancel";
	gotoxy(10, 13);

	std::cout << "Foods";
	mode_u16();
	gotoxy(13, 15); mode_ascii(); std::cout << F_col; mode_u16();
	std::wcout << L'\x25A0';
	mode_ascii(); std::cout << "\033[0m"; mode_u16();
	gotoxy(11, 15); if (save.get_food() == 1)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1';
	gotoxy(13, 17); mode_ascii(); std::cout << F_col; mode_u16();
	std::wcout << L'\x00D8';
	mode_ascii(); std::cout << "\033[0m"; mode_u16();
	gotoxy(11, 17); if (save.get_food() == 2)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1';
	gotoxy(13, 19); mode_ascii(); std::cout << F_col; mode_u16();
	std::wcout << L'\x25CF';
	mode_ascii(); std::cout << "\033[0m"; mode_u16();
	gotoxy(11, 19); if (save.get_food() == 3)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1';
	gotoxy(13, 21); mode_ascii(); std::cout << F_col; mode_u16();
	std::wcout << L'\x01D1';
	mode_ascii(); std::cout << "\033[0m"; mode_u16();
	gotoxy(11, 21); if (save.get_food() == 4)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1';
	mode_ascii();
	gotoxy(25, 13);

	std::cout << "Food colour";
	gotoxy(29, 15); std::cout << "\033[38;2;255;255;255m" << "White" << "\033[0m";
	gotoxy(27, 15); mode_u16(); if (save.get_food_col() == 1)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(29, 17); std::cout << "\033[38;2;46;197;40m" << "Green" << "\033[0m";
	gotoxy(27, 17); mode_u16(); if (save.get_food_col() == 2)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(29, 19); std::cout << "\033[38;2;210;146;62m" << "Orange" << "\033[0m";
	gotoxy(27, 19); mode_u16(); if (save.get_food_col() == 3)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();
	gotoxy(29, 21); std::cout << "\033[38;2;215;43;43m" << "Red" << "\033[0m";
	gotoxy(27, 21); mode_u16(); if (save.get_food_col() == 4)std::wcout << L'\x25A0'; else std::wcout << L'\x25A1'; mode_ascii();

	if (last.X == -1 && last.Y == -1) { gotoxy(5, 6); std::cout << "-->"; }
	else { gotoxy(last.X, last.Y); std::cout << "-->"; }
	do
	{
		input = _getch();
		if (input == 224)input = _getch();
		switch (input)
		{
		case 72:
			getxy(last.X, last.Y);
			if (last.Y == 6)break;
			gotoxy(last.X - 3, last.Y); std::cout << "   ";
			if (column == 1 && last.Y == 23)gotoxy(7, 21);
			else if (column == 2 && last.Y == 23)gotoxy(23, 21);
			else if (column == 3 && last.Y == 23)gotoxy(38, 16);
			else if (column == 4 && last.Y == 23)gotoxy(59, 16);
			else if (column <= 2 && last.Y <= 10)gotoxy(last.X - 3, last.Y - 4);
			else if (column == 1 && last.Y == 15)gotoxy(last.X - 5, 10);
			else if (column == 2 && last.Y == 15)gotoxy(last.X - 3, 10);
			else if (column <= 2 && last.Y > 15)gotoxy(last.X - 3, last.Y - 2);
			else if (column >= 3)gotoxy(last.X - 3, last.Y - 2);
			std::cout << "-->";
			getxy(last.X, last.Y);
			break;
		case 80:
			getxy(last.X, last.Y);
			/*if (last.Y == 10 && column<=2)break;
			else if (last.Y == 16)break;*/
			if (last.Y == 23)break;
			gotoxy(last.X - 3, last.Y); std::cout << "   ";
			if (last.Y == 10 && column == 1)gotoxy(7, last.Y + 5);
			else if (last.Y == 10 && column == 2)gotoxy(23, last.Y + 5);
			else if (column <= 2 && last.Y == 21)gotoxy(27, 23);
			else if (last.Y == 18 && column >= 3)gotoxy(38, 23);
			else if (column <= 2 && last.Y <= 10)gotoxy(last.X - 3, last.Y + 4);
			else if (column <= 2 && last.Y >= 15)gotoxy(last.X - 3, last.Y + 2);
			else if (column >= 3)gotoxy(last.X - 3, last.Y + 2);
			std::cout << "-->";
			getxy(last.X, last.Y);
			break;
		case 77:
			if (column == 4 && last.Y != 23)break;
			else if (last.X == 41 && last.Y == 23)break;
			else if (column == 2 && last.Y > 20 && last.Y != 23)break;
			getxy(last.X, last.Y);
			gotoxy(last.X - 3, last.Y); std::cout << "   ";
			if (last.X == 30 && last.Y == 23)gotoxy(38, 23);
			else if (column == 1)gotoxy(23, last.Y);
			else if (column == 2 && last.Y >= 15 && last.Y <= 19)gotoxy(38, last.Y - 1);
			else if (column == 2)gotoxy(38, last.Y);
			else if (column == 3)gotoxy(59, last.Y);
			std::cout << "-->";
			if (last.Y != 23)column++;
			getxy(last.X, last.Y);
			break;
		case 75:
			if (column == 1 && last.Y != 23)break;
			else if (last.X == 30 && last.Y == 23)break;
			getxy(last.X, last.Y);
			gotoxy(last.X - 3, last.Y); std::cout << "   ";
			if (last.Y == 23 && last.X == 41)gotoxy(27, 23);
			else if (column == 4)gotoxy(38, last.Y);
			else if (column == 3 && last.Y == 8)gotoxy(23, last.Y - 2);
			else if (column == 3 && last.Y == 6)gotoxy(23, last.Y);
			else if (column == 3 && (last.Y == 10 || last.Y == 12))gotoxy(23, 10);
			else if (column == 3 && last.Y >= 14)gotoxy(23, last.Y + 1);
			else if (column == 2 && last.Y <= 10)gotoxy(5, last.Y);
			else if (column == 2 && last.Y >= 15)gotoxy(7, last.Y);
			std::cout << "-->";
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
	case 3:if (last.Y == 6)save.set_values(save.get_head(), save.get_body(), 1, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 8)save.set_values(save.get_head(), save.get_body(), 2, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 10)save.set_values(save.get_head(), save.get_body(), 3, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 12)save.set_values(save.get_head(), save.get_body(), 4, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 14)save.set_values(save.get_head(), save.get_body(), 5, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 16)save.set_values(save.get_head(), save.get_body(), 6, save.get_body_col(), save.get_food(), save.get_food_col());
		  else if (last.Y == 18)save.set_values(save.get_head(), save.get_body(), 7, save.get_body_col(), save.get_food(), save.get_food_col());
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
		file.open("Snake settings.dat", std::ios::binary | std::ios::out);
		file.write((char*)&save, sizeof(save));
		file.close();
	}
	else { last.X -= 3; goto reset; }
	system("cls");
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