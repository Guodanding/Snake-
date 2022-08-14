#include<stdio.h>
#include<Windows.h>


//设置光标函数
void gotoxy(int x, int y)
{
	COORD pos = { x,y };                                     //COORD是一个结构体，相当于坐标
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);           //获得控制台的ID
	SetConsoleCursorPosition(hOut, pos);                     //设置光标位置
}


//创建地图函数
void Map()
{
	//printf("\n\n\n");
	//printf("\t     ");
	//for (int i = 0; i < 26; i++)
	//	printf("■");
	//for (int i = 0; i < 22; i++)
	//{
	//	int j = 0;
	//	printf("\n");
	//	printf("\t     ");
	//	printf("■");
	//	for (; j < 24; j++)
	//		printf("  ");
	//	printf("■");
	//}
	//printf("\n");
	//printf("\t     ");
	//for (int i = 0; i < 26; i++)
	//	printf("■");
	
	//上
	for (int i = 0; i < 52; i += 2)
	{
		gotoxy(13 + i, 3);
		printf("■");
	}
	//左
	for (int i = 0; i < 22; i++)
	{
		gotoxy(13, 3 + 1 + i);
		printf("■");
	}
	//右
	for (int i = 0; i < 22; i++)
	{
		gotoxy(63, 3 + 1 + i);
		printf("■");
	}
	//下
	for (int i = 0; i < 52; i += 2)
	{
		gotoxy(13 + i, 26);
		printf("■");
	}
}