#ifndef VARDEFINE_H
#define VARDEFINE_H
#include<Windows.h>//Windows Api
#include<conio.h>//控制台输入与输出
#include<graphics.h>//easyX图形库头文件
#include<time.h>
#include<stdio.h>
#include<math.h>
//引用Windows Multimedia API
#pragma comment(lib,"Winmm.lib")
//声明主窗口大小
#define MAXX 640
#define MAXY 480

//声明一个单元格的大小8X8，60X60格
#define CELLWIDTH  8
#define CELLHEIGHT 8

//声明游戏地图大小
#define GAMEX 60
#define GAMEY 60

//基础参数设定
#define LEFT 97
#define RIGHT 100
#define UP 119
#define DOWN 115
#define ESC 27
#define ENTER 13
//食物特征码
#define DELICIOUS 1
#define BOMB 2
#define POISON 3
#define GRASS 4
//关卡特征码
#define MISSION1 1
#define MISSION2 2
#define MISSION3 3

//定义节点结构体，包含指向后继与前驱的指针(双向链表)
typedef struct node {
	COORD cor;
	struct node *previous = NULL;//前驱
	struct node *next = NULL;//后继
}node;

typedef struct _PlayerInfo {
	char name[6];
	int PlayerMark;
}PlayerInfo;

extern COORD Bar[1000];
extern struct node* head;
extern int len;
extern HANDLE MusicHandle;
extern DWORD* pDeMap;
extern DWORD* pbWnd;
extern int currentDirection;
extern int gameRes;
extern int mark;
extern COORD Food;
extern int FoodNum;
extern int BarLen;
extern int FoodFlag;
extern MOUSEMSG msg;
extern COORD WiseGrass;
extern COORD Bomb[25];
extern COORD Poison[50];
extern int Mission;
extern IMAGE defaultImg;
extern LOGFONT f;//字体设置
extern int RunChoice;//判断是否为读档
extern time_t PoisonStartTime;//计时器判断是否重新生成毒草
extern time_t PoisonEndTime;
extern int PoisonExist;//判断毒草是否存在的标记

//以下为函数声明
void gotoxy(COORD pt);
void HideCursor();
void PrintStart();
void PrintLoading();
void PrintMenu();
void PrintMenuChoice(int Position);
void PrintMissionChoice();
void PrintChoice(int Choice);
void PrintMissionINFO();
void PrintPauseMenu();
void PauseChoiceButton(int PauseChoice);
void PrintEnd();
void PrintMapINFO();
void PrintMark();
void PrintMarkINFO();
void PrintRankList();
int JudgeRankListINFO();
int JudgeMissionOver();
void PrintMissionSuccessINFO();
void PrintAuthorINFO();
void PrintStarSky();
void setDefaultMap();
void SetSnakeINFO();
void SetFoodINFO();
void SetBarINFO();
void SetBombINFO();
void SetPoisonINFO();
void SetWiseGrassINFO();
void SetAll();
void localRefresh(COORD Tcor);

COORD getFoodCor();
int Cor_Cmp(COORD pt1, COORD pt2);
int Bomb_Cmp(COORD headcor);
int Poison_Cmp(COORD headcor);
int isDead(void);
void AddHeadNode();
void CutTailNode();

int KBlistener(int key);
int getDir(int oldDir);
int isFood();
DWORD WINAPI MusicPlayer(LPVOID lpParameter);

//移动集合
void moveUp();
void moveDown();
void moveLeft();
void moveRight();
void currentMove();
void initProj();
void initInitialDatas();
void initGame();
void initBar();

//文件操作集合
void save();
void load();
void saveRankINFO(PlayerInfo pi);
PlayerInfo loadRankINFO();
void LoadGame();

//食物集合
void FoodType();
void eatFood();
void eatBomb();
void eatPoison();
void eatWiseGrass();
void spawnDiff();
void clearPoison();

#endif // !VARDEFINE_H

