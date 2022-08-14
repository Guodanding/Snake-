#include<iostream>
using namespace std;

void Welcome();
void Map();
void gotoxy(int, int);
void InitializeSnack();
void RunTheSnake();

int main()
{
	Welcome();
	Map();
	InitializeSnack();
	RunTheSnake();
	return 0;
}
