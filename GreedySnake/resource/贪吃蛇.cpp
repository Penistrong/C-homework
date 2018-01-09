#include"vardefine.h"

int len;
node* head;
int currentDirection;//Ĭ�Ϸ���Ϊ��
COORD Bar[1000] = { 0,0 };//���崢�������ϰ�������ṹ�������
int BarLen;
int gameRes = 1;
int mark;
COORD Food;
int FoodNum;//�ܹ��Ե�ʳ��ļ������������жϺ�ʱ����������ʳ��
int FoodFlag;
DWORD* pDeMap;//Ĭ�ϵ�ͼ�Դ�
DWORD* pbWnd;//����ʵʱ�Դ�
MOUSEMSG msg;//�����Ϣ
COORD WiseGrass;//�����ǻ۲�,ͬһʱ���������ֻ��һ��
COORD Bomb[25];//�������е���������Ϣ(����25��)
COORD Poison[50];//�������ж���������Ϣ(����50��)
int Mission;//�ؿ���Ϣ
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
	initGame();//��ʼ����Ϸ����
	setDefaultMap();
	PrintMapINFO();
	PrintMissionINFO();
	while (TRUE) {
		AddHeadNode();//����������һ��������һ��ͷ�ڵ�
		//FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));//������뻺����
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
				currentMove();//�����ǹ��ܼ�ִ��Ĭ�Ϸ����ƶ�
				break;
			}
		}
		else {
			currentMove();//û�а���ִ��Ĭ�Ϸ����ƶ�
		}

		if (isDead()) {
			gameRes = 0;
		}
		else if (isFood()) {
			//�Ե�ʳ��ʱ����ɾ��β�ڵ�
			//len++;//���ȼ�������1(��eatFood�滻)
			//Food = getFoodCor();//������һ��ʳ��
			FoodType();
			spawnDiff();//���ݼ�����FoodNum�ж��Ƿ���Ҫ���ɹ�����ʳ��
			clearPoison();//��ʱɾ������(������Ե�ʳ���ʱ��)
		}else {
			//����δ����Ҳδ��ʳ��ʱ�������һ������β
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
			Sleep(1000);//����˲�䶨��
			PrintEnd();
			PrintMarkINFO();
			if (JudgeRankListINFO()) {
				char s[6];
				LPTSTR ls = 0;
				InputBox(ls,6,_T("��������������!"),_T("�¸߷֣�"),NULL,200,0,false);
				WideCharToMultiByte(CP_ACP, 0, ls, 6, s, 6, NULL,NULL);
				PlayerInfo bestplayer;
				strcpy_s(bestplayer.name, s);
				bestplayer.PlayerMark = mark;
				saveRankINFO(bestplayer);
			}
			/*if (*s != '\0') {

			}*/
			goto beginning;//�۷���Ϸ��ʼ����
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
