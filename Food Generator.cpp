#include "food generator.h"
#include <iostream>

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