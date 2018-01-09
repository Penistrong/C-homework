#ifndef VARDEFINE_H
#define VARDEFINE_H
#include<Windows.h>//Windows Api
#include<conio.h>//����̨���������
#include<graphics.h>//easyXͼ�ο�ͷ�ļ�
#include<time.h>
#include<stdio.h>
#include<math.h>
//����Windows Multimedia API
#pragma comment(lib,"Winmm.lib")
//���������ڴ�С
#define MAXX 640
#define MAXY 480

//����һ����Ԫ��Ĵ�С8X8��60X60��
#define CELLWIDTH  8
#define CELLHEIGHT 8

//������Ϸ��ͼ��С
#define GAMEX 60
#define GAMEY 60

//���������趨
#define LEFT 97
#define RIGHT 100
#define UP 119
#define DOWN 115
#define ESC 27
#define ENTER 13
//ʳ��������
#define DELICIOUS 1
#define BOMB 2
#define POISON 3
#define GRASS 4
//�ؿ�������
#define MISSION1 1
#define MISSION2 2
#define MISSION3 3

//����ڵ�ṹ�壬����ָ������ǰ����ָ��(˫������)
typedef struct node {
	COORD cor;
	struct node *previous = NULL;//ǰ��
	struct node *next = NULL;//���
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
extern LOGFONT f;//��������
extern int RunChoice;//�ж��Ƿ�Ϊ����
extern time_t PoisonStartTime;//��ʱ���ж��Ƿ��������ɶ���
extern time_t PoisonEndTime;
extern int PoisonExist;//�ж϶����Ƿ���ڵı��

//����Ϊ��������
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

//�ƶ�����
void moveUp();
void moveDown();
void moveLeft();
void moveRight();
void currentMove();
void initProj();
void initInitialDatas();
void initGame();
void initBar();

//�ļ���������
void save();
void load();
void saveRankINFO(PlayerInfo pi);
PlayerInfo loadRankINFO();
void LoadGame();

//ʳ�Ｏ��
void FoodType();
void eatFood();
void eatBomb();
void eatPoison();
void eatWiseGrass();
void spawnDiff();
void clearPoison();

#endif // !VARDEFINE_H

