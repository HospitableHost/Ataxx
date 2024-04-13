#pragma once
#define MaxDeep 3
#define OpenMaxSize 60
using namespace std;

struct change//棋局上的变化，(x0,y0)移动到(x1,y1)
{
	int x0;
	int y0;
	int x1;
	int y1;
	bool WhoMove;//此布尔变量指明是哪种棋子在移动，是AI还是玩家，若为1则是AI的棋子移动，若为0则是玩家的棋子移动
};
struct node//搜索树中的结点的定义,搜索树的存储结构采用孩子兄弟存储方式
{
	change changes[MaxDeep];//changes[i]是从第i层到第i+1层的棋盘变化，由changes[i]及之前的可以确定当前处于第i+1层的结点的棋盘状态,因此对于第i+1层的结点来说changes[0到i]才是有效的
	double val;//结点的静态估计值或者倒推估计值
	double AlphaBeta;//结点的α或β值，依据deepth来判断它是MIN层还是MAX层以判断这个变量对应Alpha还是对应Beta
	int deepth;//此变量指明此结点所在的是第几层，默认最开始是第0层
	node *child;//指向大孩子
	node *brother;//指向此结点的兄弟结点
	node *parent;//指向此结点的父节点
};
struct SearchTree
{
	node S0;//搜索树的初始状态即根节点
	node* root;//标记整棵搜索树，指向S0，即初始状态
	change best;//存放AI最好的走步，其实就是把初始状态的最好子节点的change[0]复制过来就好了
	node* open[OpenMaxSize];//open表，是一个栈
	int openptr;//open表的栈顶指针,栈顶指针指向栈顶元素
};

int PrintInterface();//打印游戏开始前的界面,返回值是用户所选功能

void PrintIntroOfGame();//打印游戏介绍

void PrintRuleOfGame();//打印游戏规则

void Init();//初始化棋局函数,或者是开始一局新游戏函数

void AskPlayerHow(int &x0, int &y0, int &x1, int &y1);//询问玩家如何走步的函数，(x0,y0)是将要移动的棋子，(x1,y1)是将要移动到的位置，通过参数的引用传递带回函数的输出

bool JudgeWhetherToMove1(int map[7][7], int x0,int y0, int x1, int y1);/*此函数判断玩家做出的走步是否合乎规则，即是否真的能走，返回值为True表明可以走，(x0,y0)是将要移动的棋子，(x1,y1)是将要移动到的位置,map参数指向地图二维数组的起始地址*/

bool JudgeWhetherToMove2(int map[7][7], int x0, int y0, int x1, int y1);/*此函数判断AI做出的走步是否合乎规则，即是否真的能走，返回值为True表明可以走，(x0,y0)是将要移动的棋子，(x1,y1)是将要移动到的位置,map参数指向地图二维数组的起始地址*/

void UpdateMap1(int x0, int y0, int x1, int y1);//此函数根据玩家作出的走步更新全局棋盘，(x0,y0)是将要移动的棋子，(x1,y1)是将要移动到的位置，此函数在main里使用

void UpdateMap2(int x0, int y0, int x1, int y1);//此函数根据AI作出的走步更新全局棋盘，(x0,y0)是将要移动的棋子，(x1,y1)是将要移动到的位置，此函数在main里使用

void UpdateMap3(int map[7][7],int x0, int y0, int x1, int y1); //此函数根据玩家作出的走步更新参数map棋盘，(x0, y0)是将要移动的棋子，(x1, y1)是将要移动到的位置，此函数在α-β算法里使用

void UpdateMap4(int map[7][7], int x0, int y0, int x1, int y1);//此函数根据AI作出的走步更新参数map棋盘，(x0,y0)是将要移动的棋子，(x1,y1)是将要移动到的位置，此函数在α-β算法里使用

void PrintMap();//此函数打印出最新的美观棋盘

bool JudgeGameOver();//此函数判断游戏是否结束,返回值为true表明游戏结束

void AICalculate(int &x0, int &y0, int &x1, int &y1);/*使用α-β剪枝法来对博弈树进行搜索，计算出AI合适的走步，(x0,y0)是将要移动的棋子，(x1,y1)是将要移动到的位置，通过参数的引用传递带回函数的输出*/

bool extendnode(SearchTree* abT, node* p, int&xx0,int&yy0,int&xx1,int&yy1,bool whetherext,bool initright);/*扩展结点函数，返回值为bool型，为true表明扩展成功或结点p可扩展，为false表明结点p不可扩展,
																								   参数p就是指向被扩展的结点,参数abT指向搜索博弈树，
																								   whetherext参数用来决定是只判断结点p能否扩展 还是 在做出这个判断的同时还扩展结点p，为0表明只判断，为1表明判断+扩展
																								   （xx0,yy0）到（xx1,yy1）用于帮助第二次调用这个函数的时候给出一个初始的探查起点，避免重新再探查一遍
																								   参数initright用于指明（xx0,yy0）到（xx1,yy1）这个初始探查起点的有效性，为1表明有效，为0表明无效
																								   （因为我们在α-β算法中是先调用一次这个函数来判断结点p是否可扩展来帮助算法的分流的，如果可扩展且满足剪枝条件的话就不再再次调用这个函数进行扩展p了，
																								   如果可扩展但是不满足剪枝条件，那么还得第二次调用这个函数来扩展结点p，为什么要这样二次调用呢？因为我们相当于让这个extendnode函数有两个功能①判断能否扩展
																								   ②对结点进行扩展，我们把这两个功能写到一个函数里边去了，由函数的参数来决定这个函数的功能，
																								   为什么要这样做呢？因为不这样做的话，由这个函数我们会在要剪枝前 判断应该剪枝了 然后又扩展了一次，这个扩展不必要）*/

void StaticEvaluateFunc(node* p, double K, double percent);//α-β剪枝法中的静态估计函数，对棋局形势做出估计，值越大表明棋局对AI越有利,参数是存放棋盘的二维数组的地址
                                                           //p是叶子结点,percent是调控参数(0<=percent<=1)，决定第一大项和第二大项的比例，K是调控参数(K>=0),决定静态估计函数中第二大项中的各小项的比例

