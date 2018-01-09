#include"vardefine.h"

int len;
node* head;
int currentDirection;//默认方向为右
COORD Bar[1000] = { 0,0 };//定义储存所有障碍物坐标结构体的数组
int BarLen;
int gameRes = 1;
int mark;
COORD Food;
int FoodNum;//总共吃得食物的计数器，用以判断何时生产功能性食物
int FoodFlag;
DWORD* pDeMap;//默认地图显存
DWORD* pbWnd;//窗体实时显存
MOUSEMSG msg;//鼠标消息
COORD WiseGrass;//储存智慧草,同一时间如果有则只有一个
COORD Bomb[25];//储存所有地雷坐标信息(上限25个)
COORD Poison[50];//储存所有毒草坐标信息(上限50个)
int Mission;//关卡信息
IMAGE defaultImg;
LOGFONT f;
int RunChoice;
time_t PoisonStartTime;
time_t PoisonEndTime;
int PoisonExist = 0;

void main() {
	initgraph(MAXX, MAXY);
	void initProj();
	//HANDLE MusicHandle = CreateThread(NULL, 0, MusicPlayer, NULL, 0, NULL);
beginning:PrintStart();
	PrintLoading();
	PrintMenu();
	PrintLoading();
	initGame();//初始化游戏数据
	setDefaultMap();
	PrintMapINFO();
	PrintMissionINFO();
	while (TRUE) {
		AddHeadNode();//不管怎样，一定会增加一个头节点
		//FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));//清空输入缓存区
		int key = 0;
		key = KBlistener(key);
		if (key != 0) {
			if ((key == UP||key == DOWN) || (key == LEFT||key == RIGHT)) {
				key = getDir(key);
			}
			switch (key) {
			case ESC:
				PrintPauseMenu();
				currentMove();
				break;
			case ENTER:
				PrintPauseMenu();
				currentMove();
				break;
			case UP:
				moveUp();
				break;
			case DOWN:
				moveDown();
				break;
			case LEFT:
				moveLeft();
				break;
			case RIGHT:
				moveRight();
				break;
			default:
				currentMove();//按键非功能键执行默认方向移动
				break;
			}
		}
		else {
			currentMove();//没有按键执行默认方向移动
		}

		if (isDead()) {
			gameRes = 0;
		}
		else if (isFood()) {
			//吃到食物时不用删除尾节点
			//len++;//长度计数器＋1(用eatFood替换)
			//Food = getFoodCor();//产生下一个食物
			FoodType();
			spawnDiff();//根据计数器FoodNum判断是否需要生成功能性食物
			clearPoison();//定时删除毒草(根据你吃的食物的时间)
		}else {
			//当既未死亡也未吃食物时，会剪掉一个旧蛇尾
			CutTailNode();
		}
		if (gameRes == -1) {
			Sleep(1000);
			closegraph();
			exit(0);
		}
		else if (gameRes == 1) {
			SetAll();
		}
		else if (gameRes == 0) {
			Sleep(1000);//死亡瞬间定格
			PrintEnd();
			PrintMarkINFO();
			if (JudgeRankListINFO()) {
				char s[6];
				LPTSTR ls = 0;
				InputBox(ls,6,_T("请输入您的名号!"),_T("新高分！"),NULL,200,0,false);
				WideCharToMultiByte(CP_ACP, 0, ls, 6, s, 6, NULL,NULL);
				PlayerInfo bestplayer;
				strcpy_s(bestplayer.name, s);
				bestplayer.PlayerMark = mark;
				saveRankINFO(bestplayer);
			}
			/*if (*s != '\0') {

			}*/
			goto beginning;//折返游戏开始界面
		}
		if (JudgeMissionOver()) {
			PrintMissionSuccessINFO();
			goto beginning;
		}
		Sleep(10);
	}
	PrintStart();
	closegraph();
}
