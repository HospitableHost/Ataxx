#include"ȫ�ֱ����ͺ����Ķ���.h"
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
	cout << "������������������������������������������������������������" << endl;
	cout << "��           ͬ����           ��" << endl;
	cout << "��                            ��" << endl;
	cout << "��                            ��" << endl;
	cout << "��         ����Ϸ����         ��" << endl;
	cout << "��         ����Ϸ����         ��" << endl;
	cout << "��         �ۿ�ʼ����Ϸ       ��" << endl;
	cout << "��         ���˳���Ϸ         ��" << endl;
	cout << "��                            ��" << endl;
	cout << "��                            ��" << endl;
	cout << "��        �������Ӧ���֣�    ��" << endl;
	cout << "��        �Ծ�������ѡ��    ��" << endl;
	cout << "��                            ��" << endl;
	cout << "������������������������������������������������������������" << endl;
	cout << " ������������ѡ��"; 
	while (true)
	{
		cin >> choice;
		if (choice < 1 || choice>4)
		{
			cout << " ������Ч�����������롣"<< endl;
			cout << " ������������ѡ��";
		}
		else
			break;
	}
	return choice;
}

void PrintIntroOfGame()
{
	system("cls"); 
	cout << "������������������������������������������������������������" << endl;
	cout << "��           ͬ����           ��" << endl;
	cout << "��                            ��" << endl;
	cout << "��                            ��" << endl;
	cout << "��          ��Ϸ���ܣ�        ��" << endl;
	cout << "��     ͬ���壨Ataxx����      ��" << endl;
	cout << "��     ��Dave Crummack        ��" << endl;
	cout << "��     ��Craig Galley         ��" << endl;
	cout << "��     ��1988�귢����һ��     ��" << endl;
	cout << "��     ����������Ϸ��         ��" << endl;
	cout << "��     1990���Ʒ�ڵ�����Ϸ   ��" << endl;
	cout << "��     ������������������˵�� ��" << endl;
	cout << "��     �ڰ����������         ��" << endl;
	cout << "��                            ��" << endl;
	cout << "������������������������������������������������������������" << endl;
	cout << " �������Ķ�������û��س�����";
	system("pause>nul");
	return;
}

void PrintRuleOfGame()
{
	system("cls");
	cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
	cout << "��                                ͬ����                                      ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                               ������ܣ�                                   ��" << endl;
	cout << "��     ��1��ͬ������һ�ֶ���������Ϸ���ڰ�˫��������7x7���������ƶ����ӡ�     ��" << endl;
	cout << "��     ��2�����ÿ�ο����ƶ���λ�������޵ģ������ƶ�����������£�            ��" << endl;
	cout << "��         ��ѡȡ�����������ϼ�����һö���ӣ���ѡ��һ������λ�ã�             ��" << endl;
	cout << "��           Ҫ�����Ӵ�Ϊ�գ���û�жԷ�Ҳû�м��������ӡ�                     ��" << endl;
	cout << "��         ��ѡ�������λ�ÿ��������¶���֮һ��                               ��" << endl;
	cout << "��           i.����λ������ѡȡ������Ϊ���ĵ�3x3�ķ�Χ�ڡ�                    ��" << endl;
	cout << "��             ��ʱѡȡ�����ӻḴ����������λ�á�                           ��" << endl;
	cout << "��             һ����8��λ�ÿ���ѡ��                                        ��" << endl;
	cout << "��           ii.����λ������ѡȡ������Ϊ���ĵ�3x3�ķ�Χ�⡢5x5�ķ�Χ�ڣ�      ��" << endl;
	cout << "��              ��ʱѡȡ�����ӻ��ƶ���������λ�ã���һ����                  ��" << endl;
	cout << "��              ��û�С�����������һ����16��λ�ÿ���ѡ��                  ��" << endl;
	cout << "��         ���ܵ���˵���ƶ�һ���ǡ�����ճ�������ƶ������ǡ�����ճ������       ��" << endl;
	cout << "��     ��3��ÿ�����Ӻ���λ�õ����ӻὫ���Ӵ����ڵ�8��λ��                   ��" << endl;
	cout << "��         ����3��3��Χ�ڣ������ӣ�����У�������Լ������ӡ�                 ��" << endl;
	cout << "��     ��4����û����������λ������Ϸ���������������ӵĵط�����                ��" << endl;
	cout << "��          ���ӿ���һ�������ӣ�Ȼ������˫���������������ʤ��                ��" << endl;
	cout << "��          ������ʱ�̶Է�������Ϊ0ʱ������ʤ����                             ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "��                                                                            ��" << endl;
	cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������" << endl;
	cout << " �������Ķ�������û��س�����";
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
	Map[6][0] = 2;//�ϱ߶��Ƕ�������ֵĳ�ʼ��
	NumOfAI = 2;
	NumOfPlayer = 2;//�����������������г�ʼ��
}

void AskPlayerHow(int &x0, int &y0, int &x1, int &y1)//���ص��ĸ�����ֵ���������е�������,�������5�к�5��ת����4����
{
A:	cout << endl;
	cout << "����������Ҫ�ƶ���ö���ӣ�" << endl;
	cout << "����������Ҫ�ƶ������ӵ��кţ�"; cin >> x0; 
	cout << "����������Ҫ�ƶ������ӵ��кţ�"; cin >> y0; 
	cout << "����������Ҫ�ƶ����ĸ�λ�ã�" << endl;
	cout << "����������Ҫ�ƶ�����λ�õ��кţ�"; cin >> x1; 
	cout << "����������Ҫ�ƶ�����λ�õ��кţ�"; cin >> y1; 
	x0--;
	y0--;
	x1--;
	y1--;
	bool whether;
	whether=JudgeWhetherToMove1(Map,x0, y0, x1, y1);
	if (whether == false)
	{
		cout << "���벻�Ϸ������������롣" << endl;
		goto A;
	}
	return;

}

bool JudgeWhetherToMove1(int map[7][7], int x0, int y0, int x1, int y1)//�ĸ������ȡֵ��Χ��0-6֮�䣬��AskPlayerHow�������Ѿ���������ȷ��Χ������ֵ
{
	bool premise1 = (x0 > -1 && x0 < 7) && (y0 > -1 && y0 < 7) && (x1 > -1 && x1 < 7) && (y1 > -1 && y1 < 7);//��֤�ĸ�����ֵ��0-6֮��
	bool premise2=false;//Ϊtrue�������ƶ�����������ҵ�����
	bool premise3=false;//Ϊtrue������Ҫ�ƶ�����λ���ǿ�λ��
	bool premise4 = false;//Ϊtrue������Ҫ�ƶ�����λ�����ܱ�λ��
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

bool JudgeWhetherToMove2(int map[7][7],int x0, int y0, int x1, int y1)//�ĸ������ȡֵ��Χ��0-6֮��
{
	bool premise1 = (x0 > -1 && x0 < 7) && (y0 > -1 && y0 < 7) && (x1 > -1 && x1 < 7) && (y1 > -1 && y1 < 7);//��֤�ĸ�����ֵ��0-6֮��
	bool premise2 = false;//Ϊtrue�������ƶ���������AI������
	bool premise3 = false;//Ϊtrue������Ҫ�ƶ�����λ���ǿ�λ��
	bool premise4 = false;//Ϊtrue������Ҫ�ƶ�����λ�����ܱ�λ��
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

void UpdateMap1(int x0, int y0, int x1, int y1)//�����������ǰҪȷ����x0,y0���ͣ�x1,y1�����Ǻ���ģ����ӣ�x0,y0������x1,y1���ǿ��ƶ���
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
	/*������˳ʱ��ͬ����x1,y1���ڽ���8��λ��*/
	int X = x1 - 1;//X��Y��������ͬ������
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

void UpdateMap2(int x0, int y0, int x1, int y1)//�����������ǰҪȷ����x0,y0���ͣ�x1,y1�����Ǻ���ģ����ӣ�x0,y0������x1,y1���ǿ��ƶ���
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
	/*������˳ʱ��ͬ����x1,y1���ڽ���8��λ��*/
	int X = x1 - 1;//X��Y��������ͬ������
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
	/*������˳ʱ��ͬ����x1,y1���ڽ���8��λ��*/
	int X = x1 - 1;//X��Y��������ͬ������
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

void UpdateMap4(int map[7][7], int x0, int y0, int x1, int y1)//�����������ǰҪȷ����x0,y0���ͣ�x1,y1�����Ǻ���ģ����ӣ�x0,y0������x1,y1���ǿ��ƶ���
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
	/*������˳ʱ��ͬ����x1,y1���ڽ���8��λ��*/
	int X = x1 - 1;//X��Y��������ͬ������
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

void PrintMap()//����Ǻ��ӣ�AI�ǰ���
{
	system("cls");
	cout << " ��AI  Ϊ�����塣"<<endl;
	cout << " �����Ϊʵ���塣" << endl;
	cout << " ����ǰ AI �����Ӹ���Ϊ��" << NumOfAI << "����" << endl;
	cout << " ����ǰ��ҵ����Ӹ���Ϊ��" << NumOfPlayer << "����" << endl;
	cout << "   1   2   3   4   5   6   7" << endl;
	cout << " ���������ש������ש������ש������ש������ש������ש�������" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << i+1<<"��";
		for (int j = 0; j < 7; j++)
		{
			if (Map[i][j] == 0)
				cout << "   ��";
			else if (Map[i][j] == 1)
				cout << " ��";
			else
				cout << " ��";
		}
		cout << endl;
		cout << " �ǩ������贈�����贈�����贈�����贈�����贈�����贈������" << endl;
	}
	cout << "7��";
	for (int j = 0; j < 7; j++)
	{
		if (Map[6][j] == 0)
			cout << "   ��";
		else if (Map[6][j] == 1)
			cout << " ��";
		else
			cout << " ��";
	}
	cout << endl;
	cout << " ���������ߩ������ߩ������ߩ������ߩ������ߩ������ߩ�������";
	return;
}

bool JudgeGameOver()
{
	cout << endl;
	bool GameOver = false;
	if (NumOfAI == 0)
	{
		GameOver = true;
		cout << "AIû�������ӣ���һ�ʤ";
		return GameOver;
	}
	if (NumOfPlayer == 0)
	{
		GameOver = true;
		cout << "���û�������ӣ�AI��ʤ";
		return GameOver;
	}
	int NumOfVacant = 0;//�����ϵĿ�λ��
	int NumOfAIAbletoMove = 0;//�����Ͽ��ƶ���AI�����Ӹ���
	int NumOfPlayerAbletoMove = 0;//�����Ͽ��ƶ�����ҵ����Ӹ���
	int x0 = 0, y0 = 0, x1 = 0, y1 = 1;



	while (x0 < 7)
	{
		while (y0 < 7)//������Ƕ��forѭ�������������49��λ��
		{
			x1 = x0 - 2;
			y1 = y0 - 2;
			if (Map[x0][y0] == 1)//AI�����ж�
			{
				while (x1 - x0 < 3)
				{
					while (y1 - y0 < 3)//������Ƕ��ѭ�������ԣ�i��j��Ϊ���ĵ�5��5�ܱ���λ���Դ˸���NumOfAIAbletoMove
					{
						bool a = JudgeWhetherToMove2(Map, x0, y0, x1, y1);
						if (a)//ֻҪ�ܱ���һ����λ�����ƶ��Ļ�����ô��ö���ӾͿ����ƶ�����û��Ҫ�ټ�⣨i��j����Χ������λ���ˣ�����ֱ��break˫��ѭ����
						{
							NumOfAIAbletoMove++;
							goto A;//����˫��ѭ�����ж���һö����
						}
						y1++;
					}
					x1++;
					y1 = y0 - 2;
				}
			}
			else if (Map[x0][y0] == 2)//��������ж�
			{
				while (x1 - x0 < 3)
				{
					while (y1 - y0 < 3)//������Ƕ��ѭ�������ԣ�i��j��Ϊ���ĵ�5��5�ܱ���λ���Դ˸���NumOfAIAbletoMove
					{
						bool a = JudgeWhetherToMove1(Map, x0, y0, x1, y1);
						if (a)//ֻҪ�ܱ���һ����λ�����ƶ��Ļ�����ô��ö���ӾͿ����ƶ�����û��Ҫ�ټ�⣨i��j����Χ������λ���ˣ�����ֱ��break˫��ѭ����
						{
							NumOfPlayerAbletoMove++;
							goto A;//����˫��ѭ�����ж���һö����
						}
						y1++;
					}
					x1++;
					y1 = y0 - 2;
				}
			}
			else//��λ����
				NumOfVacant++;

		A://���ϵ�if-else if-else�Ǵ���һ��λ�ò��������������Ĵ��룬����һ��˫�������п����ƶ������ӵĻ���������Ϸ��û�н�����û�б�Ҫ�����������̣����Բ������±ߵĴ���
			if (NumOfAIAbletoMove != 0 && NumOfPlayerAbletoMove != 0)//��˫���������ӿ����ƶ�ʱ��ֱ���ж���Ϸû�н���������false
				return GameOver;
			y0++;
		}
		x0++;
		y0 = 0;
	}




	//������������е�����һ����û�д��ϱߵĳ���return��ȥ������ζ��������һ�������ӿ��ƶ�
	if (NumOfVacant == 0 || (NumOfAIAbletoMove == 0 && NumOfPlayerAbletoMove == 0))//˫�������ӿ��ƶ�
	{
		GameOver = true;
		if (NumOfAI > NumOfPlayer)
			cout << "AI��ʤ���ȷ�ΪAI�����=" << NumOfAI << ":" << NumOfPlayer;
		else if (NumOfAI == NumOfPlayer)
			cout << "��Ϸƽ�֣��ȷ�ΪAI�����=" << NumOfAI << ":" << NumOfPlayer;
		else
			cout << "��һ�ʤ���ȷ�ΪAI����� = " << NumOfAI << ":" << NumOfPlayer;
		return GameOver;
	}
	else if (NumOfAIAbletoMove == 0 && NumOfPlayerAbletoMove != 0)//AI���ӿ��ƶ�����������ӿ��ƶ�
	{
		NumOfPlayer = NumOfVacant + NumOfPlayer;//�ѿ�λ��������
		GameOver = true;
		if (NumOfAI > NumOfPlayer)
			cout << "AI���ӿ��ƶ�����������ӿ��ƶ������ݹ��򣬽���λ�����ң����AI��ʤ���ȷ�ΪAI�����=" << NumOfAI << ":" << NumOfPlayer;
		else if (NumOfAI == NumOfPlayer)
			cout << "AI���ӿ��ƶ�����������ӿ��ƶ������ݹ��򣬽���λ�����ң������Ϸƽ�֣��ȷ�ΪAI�����=" << NumOfAI << ":" << NumOfPlayer;
		else
			cout << "AI���ӿ��ƶ�����������ӿ��ƶ������ݹ��򣬽���λ�����ң������һ�ʤ���ȷ�ΪAI�����=" << NumOfAI << ":" << NumOfPlayer;
		return GameOver;
	}
	else//������ӿ��ߣ�����AI���ӿ��ƶ�
	{
		NumOfAI = NumOfVacant + NumOfAI;//�ѿ�λ�����AI
		GameOver = true;
		if (NumOfAI > NumOfPlayer)
			cout << "������ӿ��ƶ�����AI���ӿ��ƶ������ݹ��򣬽���λ���AI�����AI��ʤ���ȷ�ΪAI�����=" << NumOfAI << ":" << NumOfPlayer;
		else if (NumOfAI == NumOfPlayer)
			cout << "������ӿ��ƶ�����AI���ӿ��ƶ������ݹ��򣬽���λ���AI�������Ϸƽ�֣��ȷ�ΪAI�����=" << NumOfAI << ":" << NumOfPlayer;
		else
			cout << "������ӿ��ƶ�����AI���ӿ��ƶ������ݹ��򣬽���λ���AI�������һ�ʤ���ȷ�ΪAI�����=" << NumOfAI << ":" << NumOfPlayer;
		return GameOver;
	}

}

void AICalculate(int &x0, int &y0, int &x1, int &y1)
{
	SearchTree ABT;//����һ��������
	extendnum = 0;
	freenum = 0;
	abnum = 0;



	//��ʼ�����������
	ABT.best.x0 = -1;//��ʼ��ABT��best
	ABT.best.x1 = -1;
	ABT.best.y0 = -1;
	ABT.best.y1 = -1;
	ABT.best.WhoMove = -1;
	ABT.S0.parent = 0;//��ʼ��ABT��S0
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
	ABT.root = &(ABT.S0);//��ʼ��ABT��root
	for (int i = 0; i < OpenMaxSize; i++)//��ʼ��ABT��open��
		ABT.open[i] = 0;
	ABT.open[0] = ABT.root;
	ABT.openptr = 0;//��ʼ��ABT��openptr

	node* current = 0;


	bool whetherext0 = false;//��������extendnode�����Ĺ���
	bool initright0 = false;//��������extendnode�����Ĺ���
	bool judgepifcan = false;//�жϽ��current�Ƿ��ܱ���չ��Ϊtrue�����ɱ���չ��Ϊfalse�������ɱ���չ
	while (ABT.openptr != -1)
	{
		//cout << "���ѭ����ʼʱABT��open���Ԫ�ظ���Ϊ" << ABT.openptr << endl;
		//cout << "���ѭ����ʼǰ���ͷ�" << freenum << "��" << endl;
		//cout << "���ѭ����ʼǰ����֦" << abnum << "��" << endl;
		//cout << "���ѭ����ʼǰ����չ" << extendnum << "��" << endl;
		current = ABT.open[ABT.openptr];//�ó�open��ջ��Ԫ��


		if (current->deepth == MaxDeep)//����ý����Ҷ�ӽ��
		{
	        StaticEvaluateFunc(current,KCAN,PERCENTCAN);
			if (current->parent->AlphaBeta == inf)//������ڵ�û�Ц����ֵʱ��ֱ�Ӹ�ֵ
				current->parent->AlphaBeta = current->val;
			else//���ڵ��Ц����ֵʱ���²���ֱ�Ӹ�ֵ
			{
				if (MaxDeep % 2 == 0)//���ڵ���MIN��,���ڵ��Ц�ֵ����ֵ���Ͻ磬ֻ���С
				{
					if (current->val < current->parent->AlphaBeta)
						current->parent->AlphaBeta = current->val;
				}
				else//���ڵ���MAX�㣬���ڵ��Ц�ֵ����ֵ���½磬ֻ����
				{ 
					if (current->val > current->parent->AlphaBeta)
						current->parent->AlphaBeta = current->val;

				}
			}
			ABT.openptr--;//��current��ָ����Ƴ�open��
		}
		else//����ý�㲻��Ҷ�ӽ��
		{
			SearchTree* abT = &ABT;
			int xx0, yy0, xx1, yy1;
			whetherext0 = false;//��������extendnode�����Ĺ���
			initright0 = false;//��������extendnode�����Ĺ���
			judgepifcan = false;//�жϽ��current�Ƿ��ܱ���չ��Ϊtrue�����ɱ���չ��Ϊfalse�������ɱ���չ
			judgepifcan = extendnode(abT,current,xx0,yy0,xx1,yy1,whetherext0,initright0);//ֻ�ж���һ���ܲ�����չ����û��ʵ�ʵ���չ
			if (!judgepifcan)//current��㲻����չ
			{
				current->val = current->AlphaBeta;//���µ�ǰ���ĵ��ƹ���ֵ
				//���������¸��ڵ�Ħ����ֵ
				if(current->parent!=0)//����и��ڵ�
				{ 
				if (current->parent->AlphaBeta == inf)//������ڵ�û�Ц����ֵʱ��ֱ�Ӹ�ֵ
					current->parent->AlphaBeta = current->val;
				else//���ڵ��Ц����ֵʱ���²���ֱ�Ӹ�ֵ
				{
					if (current->deepth % 2 == 0)//���ڵ���MIN��,���ڵ��Ц�ֵ����ֵ���Ͻ磬ֻ���С
					{
						if (current->val < current->parent->AlphaBeta)
							current->parent->AlphaBeta = current->val;
					}
					else//���ڵ���MAX�㣬���ڵ��Ц�ֵ����ֵ���½磬ֻ����
					{
						if (current->val > current->parent->AlphaBeta)
							current->parent->AlphaBeta = current->val;
					}
				}
				}
				ABT.openptr--;
				node* ptr = current->child;//ptrָ��current�ĺ��ӣ������ͷ�current�ĺ�����
				node* ptrptr = 0;//ָ����һ����Ҫ���ͷŵĺ���
				while (ptr != 0)//�ͷŵ�current�����к���
				{
					if ((current->deepth == 0)&&(ptr->val==current->val))//������ͷŵĽ���ǳ�ʼ״̬�Ķ���������������õ��߲��Ļ����ҵ��ȱ��������õ��߲�
					{
						ABT.best = ptr->changes[0];
					}
					ptrptr = ptr->brother;
					free(ptr);
					freenum++;
					ptr = ptrptr;
				}

			}
			else//��current����չʱ
			{
				double A, B;//A�Ǹ��ڵ�����ӽڵ�Ħ�ֵ��B�Ǹ��ڵ���ӽڵ�Ħ�ֵ
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

				//�ϱ���ȷ��A��B��ֵ
				if (A==inf||B==inf||A<B)//���ܼ�֦
				{
					initright0 = true;
					whetherext0 = true;
					extendnode(abT, current, xx0, yy0, xx1, yy1, whetherext0, initright0);
					extendnum++;
				}
				else//Ӧ�ü�֦,current��ʵ�Ƿϵ��ˣ�current�ĸ��ײ�����ѡcurrent��,current��valҲû��Ҫ���£�currentҲ����Ӱ�츸�ڵ�Ħ����
				{
					abnum++;
					ABT.openptr--;
					node* ptr = current->child;//ptrָ��current�ĺ��ӣ������ͷ�current�ĺ�����
					node* ptrptr = 0;//ָ����һ����Ҫ���ͷŵĺ���
					while (ptr != 0)//�ͷŵ�current�����к���
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
	cout << "���̽�������������Ĺ������ܹ��ͷ�" << freenum << "�����" << endl;
	cout << "���̽�������������Ĺ�������󹲼�֦" << abnum << "��" << endl;
	cout << "���̽�������������Ĺ����������չ" << extendnum << "��" << endl;
	x0 = ABT.best.x0;
	y0 = ABT.best.y0;
	x1 = ABT.best.x1;
	y1 = ABT.best.y1;
	return;
}

bool extendnode(SearchTree* abT, node* p,int&xx0, int&yy0, int&xx1, int&yy1, bool whetherext, bool initright)//����ֵΪbool�ͣ�Ϊtrue������չ�ɹ���Ϊfalse������չʧ��, ����p����ָ����չ�Ľ��, ����rootָ������������
{
	/*����һ�����״̬������x0,y0���ƶ�����x1��y1����������¾�����൱����չ����һ���ӽڵ㣬����x0��y0����ͬʱ�Ի��У�x1��y1����ͬ���ӽڵ㣬
	���ǿ�����Ϊ��x0��y0��������һ���ӽڵ㣬�ڽ��������Ǽٶ���չ�ӽڵ��˳���մ����Ҵ��ϵ��µ�˳����̽ÿһ����x0��y0����
	��ô���ǾͿ��Դӵ�ǰ�������к��ӽ�㰴�����˳�������̽�����ˣ������Ϳ��Ա��������Ѿ����ڵĺ��ӽ����*/
	/*���ǽ��ӵ�ǰ����չ���ĺ��ӽ��������Ӻ��ӽ��ĺ�߰������˳�������̽����̽����һ��change�����ˣ��ͽ����ˣ��Ϳ�����չ��һ���ӽڵ���*/

	bool ret=false;
	node* m=0;//mָ��p�����ұߵĺ���,m=0��ʾpû�к��ӣ�����m��ָ�����ұߵĺ���
	if (p->child != 0)
	{
		m = p->child;
		while (m->brother != 0)
			m = m->brother;
	}
	int x0, y0, x1,y1;


	//��ȷ��̽������
	if (!initright)
	{
		if (p->child == 0)//pû�к���
		{
			x0 = 0; y0 = 0; x1 = 0; y1 = 1;
		}
		else//p�к���
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

	//�ڸ���һ����Ӧp��㼴���ڵ������
	int map[7][7];//����һ���������������������̣������ȫ�ֱ���Map[7][7]���Ӱ��
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			map[i][j] = Map[i][j];//�������ѱ�ˢ��Ϊ��ǰȫ������
	for (int i = 0; i < p->deepth; i++)//�������ѭ����map�����Ѿ���Ϊ��p������ڵ��Ӧ������״̬��
	{
		if (p->changes[i].WhoMove == 0)
			UpdateMap3(map,p->changes[i].x0, p->changes[i].y0, p->changes[i].x1, p->changes[i].y1);
		else
			UpdateMap4(map,p->changes[i].x0, p->changes[i].y0, p->changes[i].x1, p->changes[i].y1);

	}


	//���ж�p����MAX�㻹��MIN��Ȼ���Դ˽���̽�飬���̽�鵽�˻������ӽڵ㲢�Զ�����open���У�����Ļ��ͻ᷵��false�������޷���չ
		if (p->deepth % 2 == 0)//�ý�㴦��MAX��
		{
			while (x0 < 7)
			{
				while (y0 < 7)
				{
					if (map[x0][y0] == 1)//�����x0,y0������AI����ʱ�ҲŶ�����ӵ��ܱ��߷���̽�飬���������ν��ѭ��
					{
						while (x1 - x0 < 3)//��ѭ��������ˣ�x0��y0����һ����ܱ�̽�⣬�ټ�����ѭ��������ɶ��������̵�̽��
						{
							while (y1 - y0 < 3)
							{

								ret = JudgeWhetherToMove2(map, x0, y0, x1, y1);
								if (!whetherext&&ret)//ֻ�ж��ܷ���չ  ��  ����չ���ڵ�
								{
									xx0 = x0;
									yy0 = y0;
									xx1 = x1;
									yy1 = y1;
									return ret;

								}
								if (whetherext&&ret)//����ӣ�x0��y0������x1��y1�����ƶ�����ô����ζ���ҵ���һ���µĺ���
								{
									if (m != 0)
									{
										m->brother = (node*)malloc(sizeof(node));//���º��������ڴ�
										m = m->brother;//mָ��p�����ұߵĺ��Ӽ����µ��������
									}
									else
									{
										m = (node*)malloc(sizeof(node));
										p->child = m;
									}
									m->AlphaBeta = inf;//�����ʼ������½ڵ㡢�º��ӵĸ�������
									m->brother = 0;
									m->child = 0;
									m->deepth = p->deepth + 1;
									m->parent = p;
									m->val = inf;
									for (int i = 0; i < m->deepth - 1; i++)//��m�İְ�p����Ч��change����m
									{
										m->changes[i] = p->changes[i];
									}
									m->changes[m->deepth - 1].x0 = x0;
									m->changes[m->deepth - 1].y0 = y0;
									m->changes[m->deepth - 1].x1 = x1;
									m->changes[m->deepth - 1].y1 = y1;
									m->changes[m->deepth - 1].WhoMove = 1;
									abT->open[abT->openptr + 1] = m;//������չ�����Ľ�����open����
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
					y0++;//x0���䣬��x0��һ����
					x1 = x0 - 2;
					y1 = y0 - 2;
						
				}
				x0++;
				y0 = 0;
			}
			return ret;
		}
		else//�ý�㴦��MIN��
		{
			while (x0 < 7)
			{
				while (y0 < 7)
				{
					if (map[x0][y0] == 2)//�����x0,y0��������ҵ���ʱ�ҲŶ�����ӵ��ܱ��߷���̽�飬���������ν��ѭ��
					{
						while (x1 - x0 < 3)//��ѭ��������ˣ�x0��y0����һ����ܱ�̽�⣬�ټ�����ѭ��������ɶ��������̵�̽��
						{
							while (y1 - y0 < 3)
							{

								ret = JudgeWhetherToMove1(map, x0, y0, x1, y1);
								if (!whetherext&&ret)//ֻ�ж��ܷ���չ  ��  ����չ���ڵ�
								{
									xx0 = x0;
									yy0 = y0;
									xx1 = x1;
									yy1 = y1;
									return ret;
								}
								if (whetherext&&ret)//����ӣ�x0��y0������x1��y1�����ƶ�����ô����ζ���ҵ���һ���µĺ���
								{
									if (m != 0)
									{
										m->brother = (node*)malloc(sizeof(node));//���º��������ڴ�
										m = m->brother;//mָ��p�����ұߵĺ��Ӽ����µ��������
									}
									else
									{
										m = (node*)malloc(sizeof(node));
										p->child = m;
									}
									m->AlphaBeta = inf;//�����ʼ������½ڵ㡢�º��ӵĸ�������
									m->brother = 0;
									m->child = 0;
									m->deepth = p->deepth + 1;
									m->parent = p;
									m->val = inf;
									for (int i = 0; i < m->deepth - 1; i++)//��m�İְ�p����Ч��change����m
									{
										m->changes[i] = p->changes[i];
									}
									m->changes[m->deepth - 1].x0 = x0;
									m->changes[m->deepth - 1].y0 = y0;
									m->changes[m->deepth - 1].x1 = x1;
									m->changes[m->deepth - 1].y1 = y1;
									m->changes[m->deepth - 1].WhoMove = 0;
									abT->open[abT->openptr + 1] = m;//������չ�����Ľ�����open����
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
					y0++;//x0���䣬��x0��һ���У�����̽����һ����x0��y0��
					x1 = x0 - 2;
					y1 = y0 - 2;
				}
				x0++;
				y0 = 0;
			}
			return ret;

		}

}

void StaticEvaluateFunc(node* p,double K,double percent)//p��Ҷ�ӽ��,percent�ǵ��ز���(0<=percent<=1)��������һ����͵ڶ�����ı�����K�ǵ��ز���(K>=0),������̬���ƺ����еڶ������еĸ�С��ı���
{
	int aroundAI[5];//aroundAI[i]��ʾ�����������ϵ���Χ�뾶Ϊ1�ķ�Ȧ��AI���ӵĸ���Ϊi+4�Ŀ�λ����
	int aroundplayer[5];//aroundplayer[i]��ʾ�����������ϵ���Χ�뾶Ϊ1�ķ�Ȧ����ҵ��ӵĸ���Ϊi+4�Ŀ�λ����
	int numofAI=0;//map��������ϵ�AI�Ӹ���
	int numofPlayer = 0;//map��������ϵ�����Ӹ���
	for (int i = 0; i < 5; i++)
		aroundAI[i] = 0;
	for (int i = 0; i < 5; i++)
		aroundplayer[i] = 0;
	int x0=0, y0=0, x1=0, y1=1;//��x0��y0���루x1��y1���������������ϱߵ����ű�
	int m,n;//m��¼AI��n��¼���
	int map[7][7];//����һ���������������������̣������ȫ�ֱ���Map[7][7]���Ӱ��
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			map[i][j] = Map[i][j];//�������ѱ�ˢ��Ϊ��ǰȫ������
	for (int i = 0; i < p->deepth; i++)//�������ѭ����map�����Ѿ���Ϊ��p����ڵ��Ӧ������״̬��
	{
		if (p->changes[i].WhoMove == 0)
			UpdateMap3(map, p->changes[i].x0, p->changes[i].y0, p->changes[i].x1, p->changes[i].y1);
		else
			UpdateMap4(map, p->changes[i].x0, p->changes[i].y0, p->changes[i].x1, p->changes[i].y1);

	}
	while (x0 < 7)//̽���������̣��޸����ű�
	{
		while (y0 < 7)
		{
			if (map[x0][y0] == 0)//(x0,y0)Ϊ��λʱ�����Ĳ�������Ч
			{
				x1 = x0 - 1;
				y1 = y0 - 1;
				m = 0;
				n = 0;
				while (x1 - x0 < 2)//̽���λ��x0��y0���ܱ߰뾶Ϊ1�ķ�Ȧ�ϵ�AI�Ӹ���m������Ӹ���n
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
				//����m��n��ֵ�޸����ű�aroundAI��aroundplayer
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