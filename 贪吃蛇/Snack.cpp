#include<stdio.h>
#include<conio.h>
#include <windows.h>


void gotoxy(int, int);
void InitializeSnack();
int MoveSnake(int direction);
void RunTheSnake();
void CreateFood();
int HaveFood(int, int);


class Snack
{
public:
	int x, y;
	Snack* next;
	Snack(int x_, int y_, Snack* next_ = NULL)
	{
		x = x_;
		y = y_;
		next = next_;
	}
};

Snack headdata(36, 7);
Snack* head = &headdata;;

void InitializeSnack()
{
	Snack* p1 = &headdata, * p2 = &headdata;
	for (int i = 0; i <= 4; i += 2)
	{
		p1 = new Snack(38 + i, 7);
		p2->next = p1;
		p2 = p1;
	}
	Snack* temp = head;
	while (temp != NULL)
	{
		gotoxy(temp->x, temp->y);
		printf("●");
		temp = temp->next;
	}
	p1 = NULL;
	p2 = NULL;
}


void RunTheSnake()
{
	gotoxy(1, 1);
	printf("goal:0");

	char ch = 'd';
	int error = 0;

	CreateFood();
	while (1)
	{
		//判断是否有输入
		if (_kbhit())
		{
			char t;
			t = _getch();               //不需要按回车
			if (t != 'w' && t != 's' && t != 'a' && t != 'd');
			else ch = t;
			error = MoveSnake(ch);

			Sleep(300);
		}
		else
		{
			error = MoveSnake(ch);

			Sleep(300);                         //控制速度500ms打印一次
		}
		if (error)
			break;
		else;
	}

	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\tYou are dead!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
}


int MoveSnake(int direction)
{
	//定义错误
	int error = 0;

	//找到尾部
	Snack* tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	//添加链表尾，蛇头
	Snack* temp;
	if (direction == 'd') //左
	{
		temp = new Snack(tail->x + 2, tail->y);
		tail->next = temp;
		tail = temp;
	}
	else if (direction == 'a') //右
	{
		temp = new Snack(tail->x - 2, tail->y);
		tail->next = temp;
		tail = temp;
	}
	else if (direction == 'w') //上
	{
		temp = new Snack(tail->x, tail->y - 1);
		tail->next = temp;
		tail = temp;
	}
	else if (direction == 's') //下
	{
		temp = new Snack(tail->x, tail->y + 1);
		tail->next = temp;
		tail = temp;
	}

	//打印
	gotoxy(tail->x, tail->y);
	printf("●");
	gotoxy(head->x, head->y);
	printf("  ");

	//删除链表头，蛇尾
	temp = head;
	head = head->next;
	//delete temp;                                       // ???????????????????????????????????????????????

	gotoxy(tail->x, tail->y);


	//吃食物 加长
	int lengthen = HaveFood(tail->x, tail->y);
	Snack* temp2;
	if (lengthen)
	{
		//新建蛇身
		if (direction == 'd') //左
		{
			temp2 = new Snack(tail->x + 2, tail->y);
			tail->next = temp2;
			tail = temp2;
		}
		else if (direction == 'a') //右
		{
			temp2 = new Snack(tail->x - 2, tail->y);
			tail->next = temp2;
			tail = temp2;
		}
		else if (direction == 'w') //上
		{
			temp2 = new Snack(tail->x, tail->y - 1);
			tail->next = temp2;
			tail = temp2;
		}
		else if (direction == 's') //下
		{
			temp2 = new Snack(tail->x, tail->y + 1);
			tail->next = temp2;
			tail = temp2;
		}

		//打印新蛇身
		gotoxy(tail->x, tail->y);
		printf("●");
	}
	else;

	//查找错误
	//1.不碰蛇身
	temp = head;
	while (temp->next->next != NULL)
	{
		if (tail->x == temp->x && tail->y == temp->y)
		{
			error = 1; 
			break;
		}
		else
			temp = temp->next;
	}


	//2.不碰墙壁
	for (int j = 3; j <= 26; j++)
	{
		if (tail->x == 14 && tail->y == j)
		{
			error = 1;
			return error;
		}
		else if(tail->x == 62 && tail->y == j)
		{
			error = 1;
			return error;
		}
		else;
	}

	for (int i = 13; i <= 63; i++)
	{
		if (tail->x == i && tail->y == 3)
		{
			error = 1;
			return error;
		}
		else if (tail->x == i && tail->y == 26)
		{
			error = 1;
			return error;
		}
		else;
	}
	

	return error;
}








