#include<time.h>
#include<stdlib.h>
#include<stdio.h>

#define length 46;
#define width 18;

void gotoxy(int, int);

int x;
int y;
int goal;

void CreateFood()
{
	srand((unsigned int)time(NULL));
	x = (rand() % 22) * 2 + 16;
	y = rand() % 18 + 6;
	gotoxy(x, y);
	printf("¡ò");
}

int HaveFood(int tail_x, int tail_y)
{
	if (tail_x == x && tail_y == y)
	{
		goal += 10;
		gotoxy(1, 1);
		printf("goal:%d", goal);
		CreateFood();
		return 1;
	}
	else return 0;
}
