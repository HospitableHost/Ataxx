#include"ȫ�ֱ����ͺ����Ķ���.h"
#include<iostream>

int Map[7][7];/* ����һ��7��7�����̣���ά�����е�һ��Ԫ�ض�Ӧ�����ϵ�һ���飬Ԫ�ص�ֵ˵���˶�Ӧ���״̬��0������Ϊ�հף�1����������AI�����ӣ�2������������ҵ����� */
int NumOfAI=0;//��ǰ�����AI�����Ӹ���
int NumOfPlayer=0;//��ǰ�������ҵ����Ӹ���
//int Map[7][7] = { {1,0,0,0,0,0,2},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{2,0,0,0,0,1,1} };
int main()
{
	int choice = 0;
A:	choice = PrintInterface();
	if (choice == 1)
	{
		PrintIntroOfGame();
		goto A;
	}
	else if (choice == 2)
	{
		PrintRuleOfGame();
		goto A;
	}
	else if (choice == 3)
	{
		system("cls");
		Init();
		PrintMap();
		int AIx0, AIy0, AIx1, AIy1;
		int Playerx0, Playery0, Playerx1, Playery1;
		bool gameover;
		while (true)
		{
			do
			{
				AskPlayerHow(Playerx0, Playery0, Playerx1, Playery1);
			} while (!JudgeWhetherToMove1(Map, Playerx0, Playery0, Playerx1, Playery1));
			UpdateMap1(Playerx0, Playery0, Playerx1, Playery1);
			PrintMap();
			gameover=JudgeGameOver();
			if (!gameover)
			{
				AICalculate(AIx0, AIy0, AIx1, AIy1);
				system("pause>nul");
				UpdateMap2(AIx0, AIy0, AIx1, AIy1);
				PrintMap();
				cout << endl << "AI���߲�Ϊ����(" << AIx0+1 << "," << AIy0+1 << ")" << "�ƶ���" << "(" << AIx1+1 << "," << AIy1+1 << ")";
				gameover = JudgeGameOver();
				if (gameover)
				{
					cout << endl;
					cout << " �������Ķ�������û��س�����";
					system("pause>nul");
					goto A;
				}
			}
			else
			{
				cout << endl;
				cout << " �������Ķ�������û��س�����";
				system("pause>nul");
				goto A;
			}
		}
	}
	else
	{
		system("cls");
		cout << "��Ϸ������";
	}

	system("pause>nul");
	return 1;
}