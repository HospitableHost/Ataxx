#include"全局变量和函数的定义.h"
#include<iostream>

int Map[7][7];/* 定义一个7×7的棋盘，二维数组中的一个元素对应棋盘上的一个块，元素的值说明了对应块的状态，0表明块为空白，1表明块上有AI的棋子，2表明块上有玩家的棋子 */
int NumOfAI=0;//当前棋局上AI的棋子个数
int NumOfPlayer=0;//当前棋局上玩家的棋子个数
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
				cout << endl << "AI的走步为：将(" << AIx0+1 << "," << AIy0+1 << ")" << "移动到" << "(" << AIx1+1 << "," << AIy1+1 << ")";
				gameover = JudgeGameOver();
				if (gameover)
				{
					cout << endl;
					cout << " →若您阅读完毕请敲击回车键。";
					system("pause>nul");
					goto A;
				}
			}
			else
			{
				cout << endl;
				cout << " →若您阅读完毕请敲击回车键。";
				system("pause>nul");
				goto A;
			}
		}
	}
	else
	{
		system("cls");
		cout << "游戏结束！";
	}

	system("pause>nul");
	return 1;
}