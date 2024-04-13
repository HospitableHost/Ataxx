#include"全局变量和函数的定义.h"
#include<iostream>
#include<stdlib.h>
#define INF 0x7fffffff
#define MaxDeep 3
#define OpenMaxSize 60
#define KCAN 0.1
#define PERCENTCAN 0.5
using namespace std;
extern int Map[7][7];
extern int NumOfAI;
extern int NumOfPlayer;
int extendnum = 0;
int freenum = 0;
int abnum = 0;
double inf = INF;

int PrintInterface()
{
	system("cls");
	int choice;
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	cout << "┃           同化棋           ┃" << endl;
	cout << "┃                            ┃" << endl;
	cout << "┃                            ┃" << endl;
	cout << "┃         ①游戏介绍         ┃" << endl;
	cout << "┃         ②游戏规则         ┃" << endl;
	cout << "┃         ③开始新游戏       ┃" << endl;
	cout << "┃         ④退出游戏         ┃" << endl;
	cout << "┃                            ┃" << endl;
	cout << "┃                            ┃" << endl;
	cout << "┃        请输入对应数字，    ┃" << endl;
	cout << "┃        以决定您的选择。    ┃" << endl;
	cout << "┃                            ┃" << endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	cout << " →请输入您的选择："; 
	while (true)
	{
		cin >> choice;
		if (choice < 1 || choice>4)
		{
			cout << " 输入无效，请重新输入。"<< endl;
			cout << " →请输入您的选择：";
		}
		else
			break;
	}
	return choice;
}

void PrintIntroOfGame()
{
	system("cls"); 
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	cout << "┃           同化棋           ┃" << endl;
	cout << "┃                            ┃" << endl;
	cout << "┃                            ┃" << endl;
	cout << "┃          游戏介绍：        ┃" << endl;
	cout << "┃     同化棋（Ataxx），      ┃" << endl;
	cout << "┃     是Dave Crummack        ┃" << endl;
	cout << "┃     和Craig Galley         ┃" << endl;
	cout << "┃     在1988年发明的一种     ┃" << endl;
	cout << "┃     两人棋类游戏，         ┃" << endl;
	cout << "┃     1990年出品于电视游戏   ┃" << endl;
	cout << "┃     而流行了起来，可以说是 ┃" << endl;
	cout << "┃     黑白棋的衍生。         ┃" << endl;
	cout << "┃                            ┃" << endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	cout << " →若您阅读完毕请敲击回车键。";
	system("pause>nul");
	return;
}

void PrintRuleOfGame()
{
	system("cls");
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	cout << "┃                                同化棋                                      ┃" << endl;
	cout << "┃                                                                            ┃" << endl;
	cout << "┃                                                                            ┃" << endl;
	cout << "┃                               规则介绍：                                   ┃" << endl;
	cout << "┃     （1）同化棋是一种二人棋盘游戏，黑白双方交替在7x7的棋盘上移动棋子。     ┃" << endl;
	cout << "┃     （2）玩家每次可以移动的位置是有限的，具体移动步骤解释如下：            ┃" << endl;
	cout << "┃         ①选取现在在棋盘上己方的一枚棋子，再选择一个落子位置，             ┃" << endl;
	cout << "┃           要求落子处为空，既没有对方也没有己方的棋子。                     ┃" << endl;
	cout << "┃         ②选择的落子位置可以是以下二者之一：                               ┃" << endl;
	cout << "┃           i.落子位置在以选取的棋子为中心的3x3的范围内。                    ┃" << endl;
	cout << "┃             此时选取的棋子会复制自身到落子位置。                           ┃" << endl;
	cout << "┃             一共有8个位置可以选择。                                        ┃" << endl;
	cout << "┃           ii.落子位置在以选取的棋子为中心的3x3的范围外、5x5的范围内，      ┃" << endl;
	cout << "┃              此时选取的棋子会移动自身到落子位置，这一过程                  ┃" << endl;
	cout << "┃              并没有“复制自身”，一共有16个位置可以选择。                  ┃" << endl;
	cout << "┃         ③总的来说，移动一格是“复制粘贴”，移动两格是“剪切粘贴”。       ┃" << endl;
	cout << "┃     （3）每次落子后，新位置的落子会将落子处紧邻的8个位置                   ┃" << endl;
	cout << "┃         （即3×3范围内）的棋子（如果有）都变成自己的棋子。                 ┃" << endl;
	cout << "┃     （4）若没有上述这种位置则游戏结束，将所有无子的地方算作                ┃" << endl;
	cout << "┃          有子可下一方的棋子，然后数出双方棋子数，棋多者胜。                ┃" << endl;
	cout << "┃          或任意时刻对方棋子数为0时，己方胜利。                             ┃" << endl;
	cout << "┃                                                                            ┃" << endl;
	cout << "┃                                                                            ┃" << endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	cout << " →若您阅读完毕请敲击回车键。";
	system("pause>nul");

}

void Init()
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
			Map[i][j] = 0;
	}
	Map[0][0] = 1;
	Map[6][6] = 1;
	Map[0][6] = 2;
	Map[6][0] = 2;//上边都是对整个棋局的初始化
	NumOfAI = 2;
	NumOfPlayer = 2;//对两个计数变量进行初始化
}

void AskPlayerHow(int &x0, int &y0, int &x1, int &y1)//返回的四个坐标值已是数组中的索引号,即输入第5行后，5已转化成4带回
{
A:	cout << endl;
	cout << "→请输入您要移动哪枚棋子：" << endl;
	cout << "→请输入您要移动的棋子的行号："; cin >> x0; 
	cout << "→请输入您要移动的棋子的列号："; cin >> y0; 
	cout << "→请输入您要移动到哪个位置：" << endl;
	cout << "→请输入您要移动到的位置的行号："; cin >> x1; 
	cout << "→请输入您要移动到的位置的列号："; cin >> y1; 
	x0--;
	y0--;
	x1--;
	y1--;
	bool whether;
	whether=JudgeWhetherToMove1(Map,x0, y0, x1, y1);
	if (whether == false)
	{
		cout << "输入不合法，请重新输入。" << endl;
		goto A;
	}
	return;

}

bool JudgeWhetherToMove1(int map[7][7], int x0, int y0, int x1, int y1)//四个坐标的取值范围在0-6之间，在AskPlayerHow函数中已经带回了正确范围的坐标值
{
	bool premise1 = (x0 > -1 && x0 < 7) && (y0 > -1 && y0 < 7) && (x1 > -1 && x1 < 7) && (y1 > -1 && y1 < 7);//保证四个坐标值在0-6之间
	bool premise2=false;//为true表明被移动的棋子是玩家的棋子
	bool premise3=false;//为true表明将要移动到的位置是空位置
	bool premise4 = false;//为true表明将要移动到的位置是周边位置
	if (map[x0][y0] == 2)
		premise2 = true;
	if (map[x1][y1] == 0)
		premise3 = true;
	int a = x0 - x1;
	int b = y0 - y1;
	if (abs(a) < 3 && abs(b) < 3)
		premise4 = true;
	bool result = premise3 && premise4 && premise2 && premise1;
	return result;
}

bool JudgeWhetherToMove2(int map[7][7],int x0, int y0, int x1, int y1)//四个坐标的取值范围在0-6之间
{
	bool premise1 = (x0 > -1 && x0 < 7) && (y0 > -1 && y0 < 7) && (x1 > -1 && x1 < 7) && (y1 > -1 && y1 < 7);//保证四个坐标值在0-6之间
	bool premise2 = false;//为true表明被移动的棋子是AI的棋子
	bool premise3 = false;//为true表明将要移动到的位置是空位置
	bool premise4 = false;//为true表明将要移动到的位置是周边位置
	if (map[x0][y0] == 1)
		premise2 = true;
	if (map[x1][y1] == 0)
		premise3 = true;
	int a = x0 - x1;
	int b = y0 - y1;
	if (abs(a) < 3 && abs(b) < 3)
		premise4 = true;
	bool result = premise3 && premise4 && premise2 && premise1;
	return result;
}

void UpdateMap1(int x0, int y0, int x1, int y1)//进入这个函数前要确保（x0,y0）和（x1,y1）都是合理的，即从（x0,y0）到（x1,y1）是可移动的
{
	int Dvalue1 = x0 - x1;
	int Dvalue2 = y0 - y1;
	if (Dvalue1 == 2 || Dvalue1 == -2 || Dvalue2 == 2 || Dvalue2 == -2)
	{
		Map[x0][y0] = 0;
		Map[x1][y1] = 2;
	}
	else
	{
		Map[x1][y1] = 2;
		NumOfPlayer++;
	}
	/*接下来顺时针同化（x1,y1）邻近的8个位置*/
	int X = x1 - 1;//X和Y用来帮助同化过程
	int Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 1)
	{
		Map[X][Y] = 2;
		NumOfAI--;
		NumOfPlayer++;
	}

	X = x1 - 1;
	Y = y1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 1)
	{
		Map[X][Y] = 2;
		NumOfAI--;
		NumOfPlayer++;
	}

	X = x1 - 1;
	Y = y1+1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 1)
	{
		Map[X][Y] = 2;
		NumOfAI--;
		NumOfPlayer++;
	}

	X = x1;
	Y = y1-1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 1)
	{
		Map[X][Y] = 2;
		NumOfAI--;
		NumOfPlayer++;
	}

	X = x1;
	Y = y1+1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 1)
	{
		Map[X][Y] = 2;
		NumOfAI--;
		NumOfPlayer++;
	}

	X = x1+1;
	Y = y1-1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 1)
	{
		Map[X][Y] = 2;
		NumOfAI--;
		NumOfPlayer++;
	}

	X = x1 + 1;
	Y = y1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 1)
	{
		Map[X][Y] = 2;
		NumOfAI--;
		NumOfPlayer++;
	}

	X = x1 + 1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 1)
	{
		Map[X][Y] = 2;
		NumOfAI--;
		NumOfPlayer++;
	}

}

void UpdateMap2(int x0, int y0, int x1, int y1)//进入这个函数前要确保（x0,y0）和（x1,y1）都是合理的，即从（x0,y0）到（x1,y1）是可移动的
{
	int Dvalue1 = x0 - x1;
	int Dvalue2 = y0 - y1;
	if (Dvalue1 == 2 || Dvalue1 == -2 || Dvalue2 == 2 || Dvalue2 == -2)
	{
		Map[x0][y0] = 0;
		Map[x1][y1] = 1;
	}
	else
	{
		Map[x1][y1] = 1;
		NumOfAI++;
	}
	/*接下来顺时针同化（x1,y1）邻近的8个位置*/
	int X = x1 - 1;//X和Y用来帮助同化过程
	int Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 2)
	{
		Map[X][Y] = 1;
		NumOfPlayer--;
		NumOfAI++;
	}

	X = x1 - 1;
	Y = y1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 2)
	{
		Map[X][Y] = 1;
		NumOfPlayer--;
		NumOfAI++;
	}

	X = x1 - 1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 2)
	{
		Map[X][Y] = 1;
		NumOfPlayer--;
		NumOfAI++;
	}

	X = x1;
	Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 2)
	{
		Map[X][Y] = 1;
		NumOfPlayer--;
		NumOfAI++;
	}

	X = x1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 2)
	{
		Map[X][Y] = 1;
		NumOfPlayer--;
		NumOfAI++;
	}

	X = x1 + 1;
	Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 2)
	{
		Map[X][Y] = 1;
		NumOfPlayer--;
		NumOfAI++;
	}

	X = x1 + 1;
	Y = y1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 2)
	{
		Map[X][Y] = 1;
		NumOfPlayer--;
		NumOfAI++;
	}

	X = x1 + 1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && Map[X][Y] == 2)
	{
		Map[X][Y] = 1;
		NumOfPlayer--;
		NumOfAI++;
	}

}

void UpdateMap3(int map[7][7], int x0, int y0, int x1, int y1)
{
	int Dvalue1 = x0 - x1;
	int Dvalue2 = y0 - y1;
	if (Dvalue1 == 2 || Dvalue1 == -2 || Dvalue2 == 2 || Dvalue2 == -2)
	{
		map[x0][y0] = 0;
		map[x1][y1] = 2;
	}
	else
	{
		map[x1][y1] = 2;
	}
	/*接下来顺时针同化（x1,y1）邻近的8个位置*/
	int X = x1 - 1;//X和Y用来帮助同化过程
	int Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 1)
	{
		map[X][Y] = 2;
	}

	X = x1 - 1;
	Y = y1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 1)
	{
		map[X][Y] = 2;
	}

	X = x1 - 1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 1)
	{
		map[X][Y] = 2;
	}

	X = x1;
	Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 1)
	{
		map[X][Y] = 2;
	}

	X = x1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 1)
	{
		map[X][Y] = 2;
	}

	X = x1 + 1;
	Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 1)
	{
		map[X][Y] = 2;
	}

	X = x1 + 1;
	Y = y1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 1)
	{
		map[X][Y] = 2;
	}

	X = x1 + 1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 1)
	{
		map[X][Y] = 2;
	}

}

void UpdateMap4(int map[7][7], int x0, int y0, int x1, int y1)//进入这个函数前要确保（x0,y0）和（x1,y1）都是合理的，即从（x0,y0）到（x1,y1）是可移动的
{
	int Dvalue1 = x0 - x1;
	int Dvalue2 = y0 - y1;
	if (Dvalue1 == 2 || Dvalue1 == -2 || Dvalue2 == 2 || Dvalue2 == -2)
	{
		map[x0][y0] = 0;
		map[x1][y1] = 1;
	}
	else
	{
		map[x1][y1] = 1;
	}
	/*接下来顺时针同化（x1,y1）邻近的8个位置*/
	int X = x1 - 1;//X和Y用来帮助同化过程
	int Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 2)
	{
		map[X][Y] = 1;
	}

	X = x1 - 1;
	Y = y1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 2)
	{
		map[X][Y] = 1;
	}

	X = x1 - 1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 2)
	{
		map[X][Y] = 1;
	}

	X = x1;
	Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 2)
	{
		map[X][Y] = 1;
	}

	X = x1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 2)
	{
		map[X][Y] = 1;
	}

	X = x1 + 1;
	Y = y1 - 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 2)
	{
		map[X][Y] = 1;
	}

	X = x1 + 1;
	Y = y1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 2)
	{
		map[X][Y] = 1;
	}

	X = x1 + 1;
	Y = y1 + 1;
	if ((X > -1 && X < 7) && (Y > -1 && Y < 7) && map[X][Y] == 2)
	{
		map[X][Y] = 1;
	}

}

void PrintMap()//玩家是黑子，AI是白子
{
	system("cls");
	cout << " →AI  为空心棋。"<<endl;
	cout << " →玩家为实心棋。" << endl;
	cout << " →当前 AI 的棋子个数为：" << NumOfAI << "个。" << endl;
	cout << " →当前玩家的棋子个数为：" << NumOfPlayer << "个。" << endl;
	cout << "   1   2   3   4   5   6   7" << endl;
	cout << " ┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << i+1<<"┃";
		for (int j = 0; j < 7; j++)
		{
			if (Map[i][j] == 0)
				cout << "   ┃";
			else if (Map[i][j] == 1)
				cout << " ○┃";
			else
				cout << " ●┃";
		}
		cout << endl;
		cout << " ┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫" << endl;
	}
	cout << "7┃";
	for (int j = 0; j < 7; j++)
	{
		if (Map[6][j] == 0)
			cout << "   ┃";
		else if (Map[6][j] == 1)
			cout << " ○┃";
		else
			cout << " ●┃";
	}
	cout << endl;
	cout << " ┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛";
	return;
}

bool JudgeGameOver()
{
	cout << endl;
	bool GameOver = false;
	if (NumOfAI == 0)
	{
		GameOver = true;
		cout << "AI没有了棋子，玩家获胜";
		return GameOver;
	}
	if (NumOfPlayer == 0)
	{
		GameOver = true;
		cout << "玩家没有了棋子，AI获胜";
		return GameOver;
	}
	int NumOfVacant = 0;//棋盘上的空位数
	int NumOfAIAbletoMove = 0;//棋盘上可移动的AI的棋子个数
	int NumOfPlayerAbletoMove = 0;//棋盘上可移动的玩家的棋子个数
	int x0 = 0, y0 = 0, x1 = 0, y1 = 1;



	while (x0 < 7)
	{
		while (y0 < 7)//这两个嵌套for循环遍历整个棋局49个位置
		{
			x1 = x0 - 2;
			y1 = y0 - 2;
			if (Map[x0][y0] == 1)//AI棋子判断
			{
				while (x1 - x0 < 3)
				{
					while (y1 - y0 < 3)//这两个嵌套循环遍历以（i，j）为中心的5×5周边棋位，以此更正NumOfAIAbletoMove
					{
						bool a = JudgeWhetherToMove2(Map, x0, y0, x1, y1);
						if (a)//只要周边有一个空位可以移动的话，那么这枚棋子就可以移动，就没必要再检测（i，j）周围的其余位置了，可以直接break双重循环了
						{
							NumOfAIAbletoMove++;
							goto A;//跳出双重循环，判断下一枚棋子
						}
						y1++;
					}
					x1++;
					y1 = y0 - 2;
				}
			}
			else if (Map[x0][y0] == 2)//玩家棋子判断
			{
				while (x1 - x0 < 3)
				{
					while (y1 - y0 < 3)//这两个嵌套循环遍历以（i，j）为中心的5×5周边棋位，以此更正NumOfAIAbletoMove
					{
						bool a = JudgeWhetherToMove1(Map, x0, y0, x1, y1);
						if (a)//只要周边有一个空位可以移动的话，那么这枚棋子就可以移动，就没必要再检测（i，j）周围的其余位置了，可以直接break双重循环了
						{
							NumOfPlayerAbletoMove++;
							goto A;//跳出双重循环，判断下一枚棋子
						}
						y1++;
					}
					x1++;
					y1 = y0 - 2;
				}
			}
			else//空位处理
				NumOfVacant++;

		A://以上的if-else if-else是处理一个位置并更正三个变量的代码，但是一旦双方都还有可以移动的棋子的话很明显游戏还没有结束，没有必要遍历整个棋盘，所以才有了下边的代码
			if (NumOfAIAbletoMove != 0 && NumOfPlayerAbletoMove != 0)//当双方都有棋子可以移动时，直接判定游戏没有结束，返回false
				return GameOver;
			y0++;
		}
		x0++;
		y0 = 0;
	}




	//这个函数能运行到这里一定是没有从上边的出口return出去，就意味着至少有一方无棋子可移动
	if (NumOfVacant == 0 || (NumOfAIAbletoMove == 0 && NumOfPlayerAbletoMove == 0))//双方都无子可移动
	{
		GameOver = true;
		if (NumOfAI > NumOfPlayer)
			cout << "AI获胜，比分为AI：玩家=" << NumOfAI << ":" << NumOfPlayer;
		else if (NumOfAI == NumOfPlayer)
			cout << "游戏平局，比分为AI：玩家=" << NumOfAI << ":" << NumOfPlayer;
		else
			cout << "玩家获胜，比分为AI：玩家 = " << NumOfAI << ":" << NumOfPlayer;
		return GameOver;
	}
	else if (NumOfAIAbletoMove == 0 && NumOfPlayerAbletoMove != 0)//AI无子可移动，但玩家有子可移动
	{
		NumOfPlayer = NumOfVacant + NumOfPlayer;//把空位都算给玩家
		GameOver = true;
		if (NumOfAI > NumOfPlayer)
			cout << "AI无子可移动，但玩家有子可移动，根据规则，将空位算给玩家，结果AI获胜，比分为AI：玩家=" << NumOfAI << ":" << NumOfPlayer;
		else if (NumOfAI == NumOfPlayer)
			cout << "AI无子可移动，但玩家有子可移动，根据规则，将空位算给玩家，结果游戏平局，比分为AI：玩家=" << NumOfAI << ":" << NumOfPlayer;
		else
			cout << "AI无子可移动，但玩家有子可移动，根据规则，将空位算给玩家，结果玩家获胜，比分为AI：玩家=" << NumOfAI << ":" << NumOfPlayer;
		return GameOver;
	}
	else//玩家无子可走，但是AI有子可移动
	{
		NumOfAI = NumOfVacant + NumOfAI;//把空位都算给AI
		GameOver = true;
		if (NumOfAI > NumOfPlayer)
			cout << "玩家无子可移动，但AI有子可移动，根据规则，将空位算给AI，结果AI获胜，比分为AI：玩家=" << NumOfAI << ":" << NumOfPlayer;
		else if (NumOfAI == NumOfPlayer)
			cout << "玩家无子可移动，但AI有子可移动，根据规则，将空位算给AI，结果游戏平局，比分为AI：玩家=" << NumOfAI << ":" << NumOfPlayer;
		else
			cout << "玩家无子可移动，但AI有子可移动，根据规则，将空位算给AI，结果玩家获胜，比分为AI：玩家=" << NumOfAI << ":" << NumOfPlayer;
		return GameOver;
	}

}

void AICalculate(int &x0, int &y0, int &x1, int &y1)
{
	SearchTree ABT;//定义一个搜索树
	extendnum = 0;
	freenum = 0;
	abnum = 0;



	//初始化这棵搜索树
	ABT.best.x0 = -1;//初始化ABT的best
	ABT.best.x1 = -1;
	ABT.best.y0 = -1;
	ABT.best.y1 = -1;
	ABT.best.WhoMove = -1;
	ABT.S0.parent = 0;//初始化ABT的S0
	ABT.S0.val = inf;
	ABT.S0.deepth = 0;
	ABT.S0.child = 0;
	ABT.S0.brother = 0;
	ABT.S0.AlphaBeta = inf;
	for (int i = 0; i < MaxDeep; i++)
	{
		ABT.S0.changes[i].x0 = -1;
		ABT.S0.changes[i].x1 = -1;
		ABT.S0.changes[i].y0 = -1;
		ABT.S0.changes[i].y1 = -1;
		ABT.S0.changes[i].WhoMove = -1;
	}
	ABT.root = &(ABT.S0);//初始化ABT的root
	for (int i = 0; i < OpenMaxSize; i++)//初始化ABT的open表
		ABT.open[i] = 0;
	ABT.open[0] = ABT.root;
	ABT.openptr = 0;//初始化ABT的openptr

	node* current = 0;


	bool whetherext0 = false;//用来调控extendnode函数的功能
	bool initright0 = false;//用来调控extendnode函数的功能
	bool judgepifcan = false;//判断结点current是否能被扩展，为true表明可被扩展，为false表明不可被扩展
	while (ABT.openptr != -1)
	{
		//cout << "这次循环开始时ABT的open表的元素个数为" << ABT.openptr << endl;
		//cout << "这次循环开始前共释放" << freenum << "次" << endl;
		//cout << "这次循环开始前共剪枝" << abnum << "次" << endl;
		//cout << "这次循环开始前共扩展" << extendnum << "次" << endl;
		current = ABT.open[ABT.openptr];//拿出open表栈顶元素


		if (current->deepth == MaxDeep)//如果该结点是叶子结点
		{
	        StaticEvaluateFunc(current,KCAN,PERCENTCAN);
			if (current->parent->AlphaBeta == inf)//如果父节点没有α或β值时是直接赋值
				current->parent->AlphaBeta = current->val;
			else//父节点有α或β值时更新并非直接赋值
			{
				if (MaxDeep % 2 == 0)//父节点是MIN层,父节点有β值，β值是上界，只会变小
				{
					if (current->val < current->parent->AlphaBeta)
						current->parent->AlphaBeta = current->val;
				}
				else//父节点是MAX层，父节点有α值，α值是下界，只会变大
				{ 
					if (current->val > current->parent->AlphaBeta)
						current->parent->AlphaBeta = current->val;

				}
			}
			ABT.openptr--;//把current所指结点移出open表
		}
		else//如果该结点不是叶子结点
		{
			SearchTree* abT = &ABT;
			int xx0, yy0, xx1, yy1;
			whetherext0 = false;//用来调控extendnode函数的功能
			initright0 = false;//用来调控extendnode函数的功能
			judgepifcan = false;//判断结点current是否能被扩展，为true表明可被扩展，为false表明不可被扩展
			judgepifcan = extendnode(abT,current,xx0,yy0,xx1,yy1,whetherext0,initright0);//只判断了一下能不能扩展，并没有实际的扩展
			if (!judgepifcan)//current结点不可扩展
			{
				current->val = current->AlphaBeta;//更新当前结点的倒推估计值
				//接下来更新父节点的α或β值
				if(current->parent!=0)//如果有父节点
				{ 
				if (current->parent->AlphaBeta == inf)//如果父节点没有α或β值时是直接赋值
					current->parent->AlphaBeta = current->val;
				else//父节点有α或β值时更新并非直接赋值
				{
					if (current->deepth % 2 == 0)//父节点是MIN层,父节点有β值，β值是上界，只会变小
					{
						if (current->val < current->parent->AlphaBeta)
							current->parent->AlphaBeta = current->val;
					}
					else//父节点是MAX层，父节点有α值，α值是下界，只会变大
					{
						if (current->val > current->parent->AlphaBeta)
							current->parent->AlphaBeta = current->val;
					}
				}
				}
				ABT.openptr--;
				node* ptr = current->child;//ptr指向current的孩子，帮助释放current的孩子们
				node* ptrptr = 0;//指向下一个将要被释放的孩子
				while (ptr != 0)//释放掉current的所有孩子
				{
					if ((current->deepth == 0)&&(ptr->val==current->val))//如果被释放的结点是初始状态的儿子且这个结点是最好的走步的话，我得先保存这个最好的走步
					{
						ABT.best = ptr->changes[0];
					}
					ptrptr = ptr->brother;
					free(ptr);
					freenum++;
					ptr = ptrptr;
				}

			}
			else//当current可扩展时
			{
				double A, B;//A是父节点或者子节点的α值，B是父节点或子节点的β值
				if(current->parent!=0)
				{ 
				   if (current->deepth % 2 == 0)
				{
					A = current->AlphaBeta;
					B = current->parent->AlphaBeta;
				}
				   else
				{
					B = current->AlphaBeta;
					A = current->parent->AlphaBeta;
				}
				}
				else
				{
					A = current->AlphaBeta;
					B = inf;
				}

				//上边是确定A、B的值
				if (A==inf||B==inf||A<B)//不能剪枝
				{
					initright0 = true;
					whetherext0 = true;
					extendnode(abT, current, xx0, yy0, xx1, yy1, whetherext0, initright0);
					extendnum++;
				}
				else//应该剪枝,current其实是废掉了，current的父亲不会再选current了,current的val也没必要更新，current也不会影响父节点的α或β
				{
					abnum++;
					ABT.openptr--;
					node* ptr = current->child;//ptr指向current的孩子，帮助释放current的孩子们
					node* ptrptr = 0;//指向下一个将要被释放的孩子
					while (ptr != 0)//释放掉current的所有孩子
					{
						ptrptr = ptr->brother;
						free(ptr);
						freenum++;
						ptr = ptrptr;
					}

				}
			}
		}
	}
	cout << "这次探查搜索博弈树的过程中总共释放" << freenum << "个结点" << endl;
	cout << "这次探查搜索博弈树的过程中最后共剪枝" << abnum << "次" << endl;
	cout << "这次探查搜索博弈树的过程中最后共扩展" << extendnum << "次" << endl;
	x0 = ABT.best.x0;
	y0 = ABT.best.y0;
	x1 = ABT.best.x1;
	y1 = ABT.best.y1;
	return;
}

bool extendnode(SearchTree* abT, node* p,int&xx0, int&yy0, int&xx1, int&yy1, bool whetherext, bool initright)//返回值为bool型，为true表明扩展成功，为false表明扩展失败, 参数p就是指向被扩展的结点, 参数root指向搜索博弈树
{
	/*对于一个棋局状态，将（x0,y0）移动到（x1，y1）后产生的新局面就相当于扩展出了一个子节点，当（x0，y0）相同时仍会有（x1，y1）不同的子节点，
	我们可以认为（x0，y0）决定了一类子节点，在接下来我们假定扩展子节点的顺序按照从左到右从上到下的顺序试探每一个（x0，y0），
	那么我们就可以从当前结点的现有孩子结点按着这个顺序向后试探就行了，这样就可以避免生成已经存在的孩子结点了*/
	/*我们将从当前带扩展结点的孩子结点出发，从孩子结点的后边按着这个顺序继续试探，试探到第一个change就行了，就结束了，就可以扩展出一个子节点了*/

	bool ret=false;
	node* m=0;//m指向p的最右边的孩子,m=0表示p没有孩子，否则m就指向最右边的孩子
	if (p->child != 0)
	{
		m = p->child;
		while (m->brother != 0)
			m = m->brother;
	}
	int x0, y0, x1,y1;


	//①确定探查的起点
	if (!initright)
	{
		if (p->child == 0)//p没有孩子
		{
			x0 = 0; y0 = 0; x1 = 0; y1 = 1;
		}
		else//p有孩子
		{
			x0 = m->changes[p->deepth].x0;
			y0 = m->changes[p->deepth].y0;
			x1 = m->changes[p->deepth].x1;
			y1 = m->changes[p->deepth].y1 + 1;
		}
	}
	else
	{
		x0 = xx0;
		y0 = yy0;
		x1 = xx1;
		y1 = yy1;
	}

	//②给出一个对应p结点即父节点的棋盘
	int map[7][7];//定义一个新棋盘来帮助搜索过程，以免对全局变量Map[7][7]造成影响
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			map[i][j] = Map[i][j];//新棋盘已被刷新为当前全局棋盘
	for (int i = 0; i < p->deepth; i++)//经过这个循环，map棋盘已经成为了p这个父节点对应的棋盘状态了
	{
		if (p->changes[i].WhoMove == 0)
			UpdateMap3(map,p->changes[i].x0, p->changes[i].y0, p->changes[i].x1, p->changes[i].y1);
		else
			UpdateMap4(map,p->changes[i].x0, p->changes[i].y0, p->changes[i].x1, p->changes[i].y1);

	}


	//③判断p处于MAX层还是MIN层然后以此进行探查，如果探查到了会生成子节点并自动放入open表中，否则的话就会返回false，表明无法扩展
		if (p->deepth % 2 == 0)//该结点处于MAX层
		{
			while (x0 < 7)
			{
				while (y0 < 7)
				{
					if (map[x0][y0] == 1)//如果（x0,y0）上有AI的子时我才对这个子的周边走法做探查，否则会做无谓的循环
					{
						while (x1 - x0 < 3)//此循环仅完成了（x0，y0）这一点的周边探测，再加上外循环才能完成对整个棋盘的探测
						{
							while (y1 - y0 < 3)
							{

								ret = JudgeWhetherToMove2(map, x0, y0, x1, y1);
								if (!whetherext&&ret)//只判断能否扩展  且  能扩展父节点
								{
									xx0 = x0;
									yy0 = y0;
									xx1 = x1;
									yy1 = y1;
									return ret;

								}
								if (whetherext&&ret)//如果从（x0，y0）到（x1，y1）可移动，那么就意味着找到了一个新的孩子
								{
									if (m != 0)
									{
										m->brother = (node*)malloc(sizeof(node));//给新孩子申请内存
										m = m->brother;//m指向p的最右边的孩子即最新的这个孩子
									}
									else
									{
										m = (node*)malloc(sizeof(node));
										p->child = m;
									}
									m->AlphaBeta = inf;//下面初始化这个新节点、新孩子的各个参数
									m->brother = 0;
									m->child = 0;
									m->deepth = p->deepth + 1;
									m->parent = p;
									m->val = inf;
									for (int i = 0; i < m->deepth - 1; i++)//把m的爸爸p的有效的change都给m
									{
										m->changes[i] = p->changes[i];
									}
									m->changes[m->deepth - 1].x0 = x0;
									m->changes[m->deepth - 1].y0 = y0;
									m->changes[m->deepth - 1].x1 = x1;
									m->changes[m->deepth - 1].y1 = y1;
									m->changes[m->deepth - 1].WhoMove = 1;
									abT->open[abT->openptr + 1] = m;//把新扩展出来的结点放入open表中
									abT->openptr++;
									xx0 = x0;
									yy0 = y0;
									xx1 = x1;
									yy1 = y1;
									return ret;
								}
								y1++;
							}
							x1++;
							y1 = y0 - 2;
						}
					}
					y0++;//x0不变，在x0这一行中
					x1 = x0 - 2;
					y1 = y0 - 2;
						
				}
				x0++;
				y0 = 0;
			}
			return ret;
		}
		else//该结点处于MIN层
		{
			while (x0 < 7)
			{
				while (y0 < 7)
				{
					if (map[x0][y0] == 2)//如果（x0,y0）上有玩家的子时我才对这个子的周边走法做探查，否则会做无谓的循环
					{
						while (x1 - x0 < 3)//此循环仅完成了（x0，y0）这一点的周边探测，再加上外循环才能完成对整个棋盘的探测
						{
							while (y1 - y0 < 3)
							{

								ret = JudgeWhetherToMove1(map, x0, y0, x1, y1);
								if (!whetherext&&ret)//只判断能否扩展  且  能扩展父节点
								{
									xx0 = x0;
									yy0 = y0;
									xx1 = x1;
									yy1 = y1;
									return ret;
								}
								if (whetherext&&ret)//如果从（x0，y0）到（x1，y1）可移动，那么就意味着找到了一个新的孩子
								{
									if (m != 0)
									{
										m->brother = (node*)malloc(sizeof(node));//给新孩子申请内存
										m = m->brother;//m指向p的最右边的孩子即最新的这个孩子
									}
									else
									{
										m = (node*)malloc(sizeof(node));
										p->child = m;
									}
									m->AlphaBeta = inf;//下面初始化这个新节点、新孩子的各个参数
									m->brother = 0;
									m->child = 0;
									m->deepth = p->deepth + 1;
									m->parent = p;
									m->val = inf;
									for (int i = 0; i < m->deepth - 1; i++)//把m的爸爸p的有效的change都给m
									{
										m->changes[i] = p->changes[i];
									}
									m->changes[m->deepth - 1].x0 = x0;
									m->changes[m->deepth - 1].y0 = y0;
									m->changes[m->deepth - 1].x1 = x1;
									m->changes[m->deepth - 1].y1 = y1;
									m->changes[m->deepth - 1].WhoMove = 0;
									abT->open[abT->openptr + 1] = m;//把新扩展出来的结点放入open表中
									abT->openptr++;
									xx0 = x0;
									yy0 = y0;
									xx1 = x1;
									yy1 = y1;
									return ret;
								}
								y1++;
							}
							x1++;
							y1 = y0 - 2;
						}
					}
					y0++;//x0不变，在x0这一行中，继续探查下一个（x0，y0）
					x1 = x0 - 2;
					y1 = y0 - 2;
				}
				x0++;
				y0 = 0;
			}
			return ret;

		}

}

void StaticEvaluateFunc(node* p,double K,double percent)//p是叶子结点,percent是调控参数(0<=percent<=1)，决定第一大项和第二大项的比例，K是调控参数(K>=0),决定静态估计函数中第二大项中的各小项的比例
{
	int aroundAI[5];//aroundAI[i]表示在整个棋盘上的周围半径为1的方圈上AI的子的个数为i+4的空位总数
	int aroundplayer[5];//aroundplayer[i]表示在整个棋盘上的周围半径为1的方圈上玩家的子的个数为i+4的空位总数
	int numofAI=0;//map这个棋盘上的AI子个数
	int numofPlayer = 0;//map这个棋盘上的玩家子个数
	for (int i = 0; i < 5; i++)
		aroundAI[i] = 0;
	for (int i = 0; i < 5; i++)
		aroundplayer[i] = 0;
	int x0=0, y0=0, x1=0, y1=1;//（x0，y0）与（x1，y1）用来帮助计算上边的两张表
	int m,n;//m记录AI，n记录玩家
	int map[7][7];//定义一个新棋盘来帮助搜索过程，以免对全局变量Map[7][7]造成影响
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			map[i][j] = Map[i][j];//新棋盘已被刷新为当前全局棋盘
	for (int i = 0; i < p->deepth; i++)//经过这个循环，map棋盘已经成为了p这个节点对应的棋盘状态了
	{
		if (p->changes[i].WhoMove == 0)
			UpdateMap3(map, p->changes[i].x0, p->changes[i].y0, p->changes[i].x1, p->changes[i].y1);
		else
			UpdateMap4(map, p->changes[i].x0, p->changes[i].y0, p->changes[i].x1, p->changes[i].y1);

	}
	while (x0 < 7)//探查整个棋盘，修改两张表
	{
		while (y0 < 7)
		{
			if (map[x0][y0] == 0)//(x0,y0)为空位时这样的操作才有效
			{
				x1 = x0 - 1;
				y1 = y0 - 1;
				m = 0;
				n = 0;
				while (x1 - x0 < 2)//探查空位（x0，y0）周边半径为1的方圈上的AI子个数m和玩家子个数n
				{
					while (y1 - y0 < 2)
					{
						if (map[x1][y1] == 1)
							m++;
						else if (map[x1][y1] == 2)
							n++;
						else
						{
						}
						y1++;

					}
					x1++;
					y1 = y0 - 1;
				}
				//根据m和n的值修改两张表aroundAI和aroundplayer
				switch (m) {
				case 4:
					aroundAI[0]++;
					break;
				case 5:
					aroundAI[1]++;
					break;
				case 6:
					aroundAI[2]++;
					break;
				case 7:
					aroundAI[3]++;
					break;
				case 8:
					aroundAI[4]++;
					break;
				}
				switch (n) {
				case 4:
					aroundplayer[0]++;
					break;
				case 5:
					aroundplayer[1]++;
					break;
				case 6:
					aroundplayer[2]++;
					break;
				case 7:
					aroundplayer[3]++;
					break;
				case 8:
					aroundplayer[4]++;
					break;
				}

			}
			else if (map[x0][y0] == 1)
				numofAI++;
			else
				numofPlayer++;
			y0++;
		}
		x0++;
		y0 = 0;
	}
	double sum1 = numofAI - numofPlayer;
	double sum2 = aroundplayer[0] * K + aroundplayer[1] * 1.5*K + aroundplayer[2] * 2 * K + aroundplayer[3] * 2.5*K + aroundplayer[4] * 3 * K - (aroundAI[0] * K + aroundAI[1] * 1.5*K + aroundAI[2] * 2 * K + aroundAI[3] * 2.5*K + aroundAI[4] * 3 * K);
	p->val = sum1 * percent + sum2 * (1 - percent);
		return;

}