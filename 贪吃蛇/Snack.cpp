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
		printf("��");
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
		//�ж��Ƿ�������
		if (_kbhit())
		{
			char t;
			t = _getch();               //����Ҫ���س�
			if (t != 'w' && t != 's' && t != 'a' && t != 'd');
			else ch = t;
			error = MoveSnake(ch);

			Sleep(300);
		}
		else
		{
			error = MoveSnake(ch);

			Sleep(300);                         //�����ٶ�500ms��ӡһ��
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
	//�������
	int error = 0;

	//�ҵ�β��
	Snack* tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	//�������β����ͷ
	Snack* temp;
	if (direction == 'd') //��
	{
		temp = new Snack(tail->x + 2, tail->y);
		tail->next = temp;
		tail = temp;
	}
	else if (direction == 'a') //��
	{
		temp = new Snack(tail->x - 2, tail->y);
		tail->next = temp;
		tail = temp;
	}
	else if (direction == 'w') //��
	{
		temp = new Snack(tail->x, tail->y - 1);
		tail->next = temp;
		tail = temp;
	}
	else if (direction == 's') //��
	{
		temp = new Snack(tail->x, tail->y + 1);
		tail->next = temp;
		tail = temp;
	}

	//��ӡ
	gotoxy(tail->x, tail->y);
	printf("��");
	gotoxy(head->x, head->y);
	printf("  ");

	//ɾ������ͷ����β
	temp = head;
	head = head->next;
	//delete temp;                                       // ???????????????????????????????????????????????

	gotoxy(tail->x, tail->y);


	//��ʳ�� �ӳ�
	int lengthen = HaveFood(tail->x, tail->y);
	Snack* temp2;
	if (lengthen)
	{
		//�½�����
		if (direction == 'd') //��
		{
			temp2 = new Snack(tail->x + 2, tail->y);
			tail->next = temp2;
			tail = temp2;
		}
		else if (direction == 'a') //��
		{
			temp2 = new Snack(tail->x - 2, tail->y);
			tail->next = temp2;
			tail = temp2;
		}
		else if (direction == 'w') //��
		{
			temp2 = new Snack(tail->x, tail->y - 1);
			tail->next = temp2;
			tail = temp2;
		}
		else if (direction == 's') //��
		{
			temp2 = new Snack(tail->x, tail->y + 1);
			tail->next = temp2;
			tail = temp2;
		}

		//��ӡ������
		gotoxy(tail->x, tail->y);
		printf("��");
	}
	else;

	//���Ҵ���
	//1.��������
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


	//2.����ǽ��
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








