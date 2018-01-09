#include"vardefine.h"

/**�Ӽ��̶��������Ϣ�ĺ���*/
int KBlistener(int key) {
	Sleep(20);//��Ϊ���ü�����Ϣ��Ӧ�ٶ�
	if (_kbhit())
			key = _getch();
	return key;
}

/**�õ�����(�����ж��Ƿ��ܸı䷽��)*/
int getDir(int newDir) {
	int oldDir = currentDirection;
	if (len > 1 && (abs(newDir - oldDir) == 4 || abs(newDir - oldDir) == 3))
		newDir = currentDirection;
	return newDir;
}
/**�ı���Ĭ�ϵ�ǰ������*/
void changeDirection(int dir) {
	currentDirection = dir;
}

/**��������Ƚϵĺ���*/
int Cor_Cmp(COORD pt1, COORD pt2) {
	return (pt1.X == pt2.X&&pt1.Y == pt2.Y);//��������غ��򷵻�1����ʾtrue
}
//ע��bomb��poison�Ե�ʱ������㽫��Ϣˢ����
int Bomb_Cmp(COORD headcor) {
	for (int i = 0;i < 25;i++) {
		if (Cor_Cmp(Bomb[i], headcor)) {
			Bomb[i] = { 0,0 };//�غ���Ҳ����˵�Ե��˰���һ���ÿ�
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

/**�������ʳ������,�Ҹ����겻����ǽ�ڡ������غ�*/
COORD getFoodCor() {
	COORD FoodCor;
	node* p = NULL;
	int flag;
	//srand((UINT)GetCurrentTime());
	do {
		flag = 0;//�������
		//����1-59�������
		srand((UINT)GetCurrentTime() + rand());
		FoodCor.X = 1 + rand() % (GAMEX - 1);
		FoodCor.Y = 1 + rand() % (GAMEY - 1);
		for (p = head;p != NULL;p = p->next) {
			if (Cor_Cmp(FoodCor, p->cor)) {
				flag = 1;
				break;
			}//���Ϊ1ʱ��ʾʳ���������غϣ�����ѭ�������µ�����
		}
		for (int i = 0;i < 1000;i++) {//�ж��Ƿ����ϰ����غ�
			if (Cor_Cmp(FoodCor, Bar[i])) {
				flag = 1;
				break;
			}
		}
	} while (flag == 1);
	return FoodCor;
}

/**�ж����Ƿ�������*/
int isDead() {
	int flag = 0;
	for (node*p = head->next;p != NULL;p = p->next) {
		if (Cor_Cmp(p->cor, head->cor)) {
			flag = 1;
			break;
		}		
	}
	if (flag == 0) {//�����ͷ�������������غϣ�������ж��Ƿ�ײ���ϰ���
		for (int i = 0;i < 1000;i++) {
			if (Cor_Cmp(head->cor, Bar[i])) {
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

/**���ƶ��ĺ�������(�����ͷ)*/
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

//û�в����򰴼��ǹ��ܼ�ʱ��Ĭ�Ϸ���(currentDirection)�ƶ�
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
	HWND hwnd = GetHWnd();//��ȡ������
	SetWindowText(hwnd, _T("̰���� v1.0 made BY ����ΰ"));
}

void initInitialDatas() {
	switch (RunChoice) {
	case 1://��������Ϸ���ʼ����������
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
	case 2://������Ϸ���ó�ʼ��(����LoadGame��������)
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
{//���ݹؿ���Ϣ���ɲ�ͬ��Bar��Ϣ
	int k = 0;
	switch (Mission) {
	case MISSION1:	
		for (int i = 0;i < 60;i++) {//��
			for (int j = 0;j < 60;j++) {//��
				if ((i == 0 || j == 0) || (i == 59 || j == 59)) {
					Bar[k].X = i;
					Bar[k].Y = j;
					k++;
				}
			}
		}
		BarLen = k;//��¼�ϰ�������(����ֵ+1)
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
