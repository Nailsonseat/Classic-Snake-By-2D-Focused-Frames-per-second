#include "Headers/Nailsonseat.h"
#include "file handler.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "options.h"

using namespace std;

COORD food_generator(short int notouch1, COORD notouch2, std::vector <COORD> notouch3)
{
	int temp(0);
	bool flag(true);
	srand(int(time(0)));
	COORD food({ 0,0 });
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
				else flag = true;
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
	Settings data;
	FileReader(shape_body, shape_head, body_colour, head_colour, food_colour, food_type);

menu:short int ans = menu();
	switch (ans)
	{
	case 6:break;
	case 7:
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