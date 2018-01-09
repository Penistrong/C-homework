#include"vardefine.h"

/**从键盘读入操作信息的函数*/
int KBlistener(int key) {
	Sleep(20);//人为设置键盘信息响应速度
	if (_kbhit())
			key = _getch();
	return key;
}

/**得到方向(夹杂判断是否不能改变方向)*/
int getDir(int newDir) {
	int oldDir = currentDirection;
	if (len > 1 && (abs(newDir - oldDir) == 4 || abs(newDir - oldDir) == 3))
		newDir = currentDirection;
	return newDir;
}
/**改变蛇默认的前进方向*/
void changeDirection(int dir) {
	currentDirection = dir;
}

/**进行坐标比较的函数*/
int Cor_Cmp(COORD pt1, COORD pt2) {
	return (pt1.X == pt2.X&&pt1.Y == pt2.Y);//如果坐标重合则返回1，表示true
}
//注意bomb与poison吃掉时在这里便将信息刷掉了
int Bomb_Cmp(COORD headcor) {
	for (int i = 0;i < 25;i++) {
		if (Cor_Cmp(Bomb[i], headcor)) {
			Bomb[i] = { 0,0 };//重合了也就是说吃掉了把这一个置空
			return 1;
		}
	}
	return 0;
}

int Poison_Cmp(COORD headcor) {
	for (int i = 0;i < 50;i++) {
		if (Cor_Cmp(Poison[i], headcor)) {
			Poison[i] = { 0,0 };
			return 1;
		}
	}
	return 0;
}

/**随机产生食物坐标,且该坐标不能与墙壁、蛇身重合*/
COORD getFoodCor() {
	COORD FoodCor;
	node* p = NULL;
	int flag;
	//srand((UINT)GetCurrentTime());
	do {
		flag = 0;//布尔标记
		//产生1-59的随机数
		srand((UINT)GetCurrentTime() + rand());
		FoodCor.X = 1 + rand() % (GAMEX - 1);
		FoodCor.Y = 1 + rand() % (GAMEY - 1);
		for (p = head;p != NULL;p = p->next) {
			if (Cor_Cmp(FoodCor, p->cor)) {
				flag = 1;
				break;
			}//标记为1时表示食物与蛇身重合，继续循环生成新的坐标
		}
		for (int i = 0;i < 1000;i++) {//判断是否与障碍物重合
			if (Cor_Cmp(FoodCor, Bar[i])) {
				flag = 1;
				break;
			}
		}
	} while (flag == 1);
	return FoodCor;
}

/**判断蛇是否已死亡*/
int isDead() {
	int flag = 0;
	for (node*p = head->next;p != NULL;p = p->next) {
		if (Cor_Cmp(p->cor, head->cor)) {
			flag = 1;
			break;
		}		
	}
	if (flag == 0) {//如果蛇头不与蛇身坐标重合，则继续判断是否撞到障碍物
		for (int i = 0;i < 1000;i++) {
			if (Cor_Cmp(head->cor, Bar[i])) {
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

/**蛇移动的函数集合(针对蛇头)*/
void moveUp() {
	head->cor.Y--;
	if (head->cor.Y == -1)
		head->cor.Y = 59;
	changeDirection(UP);
}

void moveDown() {
	head->cor.Y++;
	if (head->cor.Y == 60)
		head->cor.Y = 0;
	changeDirection(DOWN);
}

void moveLeft() {
	head->cor.X--;
	if (head->cor.X == -1)
		head->cor.X = 59;
	changeDirection(LEFT);
}

void moveRight() {
	head->cor.X++;
	if (head->cor.X == 60)
		head->cor.X = 0;
	changeDirection(RIGHT);
}

//没有操作或按键非功能键时按默认方向(currentDirection)移动
void currentMove() {
	switch (currentDirection) {
	case UP:
		head->cor.Y--;
		if (head->cor.Y == -1)
			head->cor.Y = 59;
		break;
	case DOWN:
		head->cor.Y++;
		if (head->cor.Y == 60)
			head->cor.Y = 0;
		break;
	case LEFT:
		head->cor.X--;
		if (head->cor.X == -1)
			head->cor.X = 59;
		break;
	case RIGHT:
		head->cor.X++;
		if (head->cor.X == 60)
			head->cor.X = 0;
		break;
	}
}

void initProj() {
	HideCursor();
	HWND hwnd = GetHWnd();//获取窗体句柄
	SetWindowText(hwnd, _T("贪吃蛇 v1.0 made BY 陈立伟"));
}

void initInitialDatas() {
	switch (RunChoice) {
	case 1://开启新游戏则初始化所有数据
		gameRes = 1;
		mark = 0;
		len = 1;
		currentDirection = RIGHT;
		FoodNum = 0;
		Food = getFoodCor();
		WiseGrass = { 0,0 };
		for (int i = 0;i < 25;i++)
			Bomb[i] = { 0,0 };
		for (int i = 0;i < 50;i++)
			Poison[i] = { 0,0 };
		break;
	case 2://加载游戏不用初始化(已在LoadGame里加载完毕)
		break;
	}
}

void initGame() {
	setfillcolor(WHITE);
	initBar();
	initInitialDatas();
	head = (node*)malloc(sizeof(node));
	head->cor.X = 28;
	head->cor.Y = 28;
	head->previous = NULL;
	head->next = NULL;
	//PrintMap();
	//FlushBatchDraw();
}

void initBar()
{//根据关卡信息生成不同的Bar信息
	int k = 0;
	switch (Mission) {
	case MISSION1:	
		for (int i = 0;i < 60;i++) {//行
			for (int j = 0;j < 60;j++) {//列
				if ((i == 0 || j == 0) || (i == 59 || j == 59)) {
					Bar[k].X = i;
					Bar[k].Y = j;
					k++;
				}
			}
		}
		BarLen = k;//记录障碍物总量(索引值+1)
		break;
	case MISSION2: 
		for (int i = 0;i < 41;i++) {
			Bar[k].X = i;
			Bar[k].Y = 41;
			k++;
			Bar[k].X = i + 19;
			Bar[k].Y = 18;
			k++;
		}
		for (int j = 0;j < 18;j++) {
			Bar[k].X = 18;
			Bar[k].Y = j;
			k++;
			Bar[k].X = 41;
			Bar[k].Y = j + 42;
			k++;
		}
		BarLen = k;
		break;
	case MISSION3:
		int k = 0;
		for (int i = 0;i < 60;i++) {
			Bar[k].Y = 29;
			Bar[k].X = i;
			k++;
		}
		for (int j = 0;j < 60;j++) {
			Bar[k].X = 29;
			Bar[k].Y = j;
			k++;
		}
		BarLen = k;
		break;
	}
}

int JudgeRankListINFO() {
	PlayerInfo pi = loadRankINFO();
	if (mark > pi.PlayerMark) {
		return 1;
	}
	else {
		return 0;
	}
}

int JudgeMissionOver() {
	switch (Mission)
	{
	case MISSION1:
		if (mark >= 5000) {
			return 1;
		}
		else {
			return 0;
		}
		break;
	case MISSION2:
		if (mark >= 20000) {
			return 1;
		}
		else {
			return 0;
		}
		break;
	case MISSION3:
		return 0;
		break;
	default:
		return 0;
		break;
	}
}
