#include<stdio.h>
#include<Windows.h>


//���ù�꺯��
void gotoxy(int x, int y)
{
	COORD pos = { x,y };                                     //COORD��һ���ṹ�壬�൱������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);           //��ÿ���̨��ID
	SetConsoleCursorPosition(hOut, pos);                     //���ù��λ��
}


//������ͼ����
void Map()
{
	//printf("\n\n\n");
	//printf("\t     ");
	//for (int i = 0; i < 26; i++)
	//	printf("��");
	//for (int i = 0; i < 22; i++)
	//{
	//	int j = 0;
	//	printf("\n");
	//	printf("\t     ");
	//	printf("��");
	//	for (; j < 24; j++)
	//		printf("  ");
	//	printf("��");
	//}
	//printf("\n");
	//printf("\t     ");
	//for (int i = 0; i < 26; i++)
	//	printf("��");
	
	//��
	for (int i = 0; i < 52; i += 2)
	{
		gotoxy(13 + i, 3);
		printf("��");
	}
	//��
	for (int i = 0; i < 22; i++)
	{
		gotoxy(13, 3 + 1 + i);
		printf("��");
	}
	//��
	for (int i = 0; i < 22; i++)
	{
		gotoxy(63, 3 + 1 + i);
		printf("��");
	}
	//��
	for (int i = 0; i < 52; i += 2)
	{
		gotoxy(13 + i, 26);
		printf("��");
	}
}