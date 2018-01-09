#include"vardefine.h"

/**加载图像至IMAGE对象中*/

/**绘制游戏开始界面*/
void PrintStart() {
	IMAGE img;
	loadimage(&img, _T("..\\res\\Begin.jpg"), 640, 480, true);
	DWORD *pbImg = GetImageBuffer(&img);
	pbWnd = GetImageBuffer();
	int r, g, b;
	for (int light = 1;light <= 256;light++) {
		for (int i = 0;i < 480 * 640;i++) {
			r = (int)(GetRValue(pbImg[i])*(light - 1) / 256);
			g = (int)(GetGValue(pbImg[i])*(light - 1) / 256);
			b = (int)(GetBValue(pbImg[i])*(light - 1) / 256);

			pbWnd[i] = RGB(r, g, b);
		}
		Sleep(10);
		FlushBatchDraw();
	}
	_getch();
}

/**绘制加载图*/
void PrintLoading() {
	//WaitForSingleObject(MusicHandle, INFINITE);
	IMAGE loadingImg;
	loadimage(&loadingImg, _T("..\\res\\loading.jpg"),640,480);
	DWORD *pbImg = GetImageBuffer(&loadingImg);
	pbWnd = GetImageBuffer();
	int r, g, b;
	for (int light = 1;light <= 256;light++) {
		for (int i = 0;i < 640 * 480;i++) {
			r = (int)(GetRValue(pbImg[i])*(light - 1) / 256);
			g = (int)(GetGValue(pbImg[i])*(light - 1) / 256);
			b = (int)(GetBValue(pbImg[i])*(light - 1) / 256);
			pbWnd[i] = RGB(r, g, b);
		}
		Sleep(20);
		FlushBatchDraw();
	}
	Sleep(100);
	for (int light = 257;light > 0;light--) {
		for (int i = 0;i < 640 * 480;i++) {
			r = (int)(GetRValue(pbImg[i])*(light - 1) / 256);
			g = (int)(GetGValue(pbImg[i])*(light - 1) / 256);
			b = (int)(GetBValue(pbImg[i])*(light - 1) / 256);
			pbWnd[i] = RGB(r, g, b);
		}
		Sleep(20);
		FlushBatchDraw();
	}
	Sleep(100);
}

/**绘制菜单包括其选择的功能*/
void PrintMenu() {
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));//清除之前玩家乱按键盘的操作
	loadimage(NULL, _T("..\\res\\menu1.jpg"), 640, 480);
	Sleep(500);
	int Position = 1;
	RunChoice = 1;
	Mission = 0;
	choice:while (TRUE) {
		if (MouseHit()) {
			msg = GetMouseMsg();
			if ((msg.x >= 280 && msg.x <= 360) && (msg.y >= 190 && msg.y <= 250)) {
				Position = 1;
				PrintMenuChoice(Position);
			}
			else if ((msg.x > 280 && msg.x <= 360) && (msg.y > 250 && msg.y <= 290)) {
				Position = 2;
				PrintMenuChoice(Position);
			}
			else if ((msg.x > 280 && msg.x <= 360) && (msg.y > 290 && msg.y <= 340)) {
				Position = 3;
				PrintMenuChoice(Position);
			}
			else if ((msg.x > 280 && msg.x <= 360) && (msg.y > 340 && msg.y <= 380)) {
				Position = 4;
				PrintMenuChoice(Position);
			}
			else if ((msg.x > 280 && msg.x <= 360) && (msg.y > 380 && msg.y <= 460)){
				Position = 5;
				PrintMenuChoice(Position);
			}
			else if (msg.uMsg == WM_LBUTTONDOWN) {
				switch (Position) {
				case 1://开启新的游戏包括选关
					RunChoice = 1;
					PrintMissionChoice();
					break;
				case 2://加载上次保存的游戏
					RunChoice = 2;
					LoadGame();
					break;
				case 3://打开排行榜
					PrintRankList();
					goto choice;//查看排行榜结束后返回菜单选项
					break;
				case 4://打开关于
					PrintAuthorINFO();
					goto choice;//查看关于结束后返回菜单选项
					break;
				case 5://退出游戏
					closegraph();
					exit(-1);
					break;
				}
			}
		}else if (_kbhit()) {
			int key = _getch();
			switch (key) {
			case UP:
				Position--;
				if (Position == 0)
					Position = 5;
				PrintMenuChoice(Position);
				break;
			case DOWN:
				Position++;
				if (Position == 6)
					Position = 1;
				PrintMenuChoice(Position);
				break;
			case ENTER:
				switch (Position) {
				case 1://开启新的游戏包括选关
					RunChoice = 1;
					PrintMissionChoice();
					break;
				case 2://加载上次保存的游戏
					RunChoice = 2;
					LoadGame();
					break;
				case 3://打开排行榜
					PrintRankList();
					goto choice;//查看排行榜结束后返回菜单选项
					break;
				case 4://打开关于
					PrintAuthorINFO();
					goto choice;//查看关于结束后返回菜单选项
					break;
				case 5://退出游戏
					closegraph();
					exit(-1);
					break;
				}
			}
		}
		if (Mission != 0) {
			break;
		}
	}
}

void PrintMenuChoice(int Position) {
	switch (Position) {
	case 1:
		loadimage(NULL, _T("..\\res\\menu1-1.jpg"), 640, 480);
		break;
	case 2:
		loadimage(NULL, _T("..\\res\\menu1-2.jpg"), 640, 480);
		break;
	case 3:
		loadimage(NULL, _T("..\\res\\menu1-3.jpg"), 640, 480);
		break;
	case 4:
		loadimage(NULL, _T("..\\res\\menu1-4.jpg"), 640, 480);
		break;
	case 5:
		loadimage(NULL, _T("..\\res\\menu1-5.jpg"), 640, 480);
		break;
	}
}

void PrintMissionChoice() {
	loadimage(NULL, _T("..\\res\\MissionChoice.jpg"), 640, 480);
	int Choice = 1;//要改
	while (TRUE) {
		if (_kbhit()) {
			int key = _getch();
			switch (key) {
			case UP:
				Choice--;
				if (Choice == 0)
					Choice = 3;
				PrintChoice(Choice);
				break;
			case DOWN:
				Choice++;
				if (Choice == 4)
					Choice = 1;
				PrintChoice(Choice);
				break;
			case ENTER:
				switch (Choice) {
				case 1:
					Mission = 1;
					break;
				case 2:
					Mission = 2;
					break;
				case 3:
					Mission = 3;
					break;
				}
				break;
			}
		}
		if (Mission != 0) {
			break;
		}
	}
}

void PrintChoice(int Choice) {
	switch (Choice) {
	case 1:
		setfillcolor(RED);
		fillcircle(80, 80, 10);
		setfillcolor(WHITE);
		fillcircle(80, 230, 10);
		fillcircle(80, 380, 10);
		break;
	case 2:
		setfillcolor(RED);
		fillcircle(80, 230, 10);
		setfillcolor(WHITE);
		fillcircle(80, 80, 10);
		fillcircle(80, 380, 10);
		break;
	case 3:
		setfillcolor(RED);
		fillcircle(80, 380, 10);
		setfillcolor(WHITE);
		fillcircle(80, 80, 10);
		fillcircle(80, 230, 10);
		break;
	}
}

void PrintPauseMenu() {
	setbkcolor(BLACK);
	IMAGE pauseImg;
	getimage(&pauseImg, 240, 160, 160, 160);//保存暂停菜单遮蔽的图片(实时显存)
	setfillcolor(BLACK);
	fillroundrect(240, 160, 399, 319, 0, 0);
	settextcolor(WHITE);
	settextstyle(16, 9, _T("Comic Sans MS"));
	outtextxy(300, 190, _T("继续游戏"));
	outtextxy(300, 270, _T("保存并退出"));
	int PauseChoice = 1;
	int breakFlag = 0;
	while (TRUE) {
		if (_kbhit()) {
			int key = _getch();
			switch (key) {
			case UP:
				PauseChoice--;
				if (PauseChoice == 0)
					PauseChoice = 2;
				PauseChoiceButton(PauseChoice);
				break;
			case DOWN:
				PauseChoice++;
				if (PauseChoice == 3)
					PauseChoice = 1;
				PauseChoiceButton(PauseChoice);
				break;
			case ENTER:
				switch (PauseChoice) {
				case 1:
					putimage(240, 160, &pauseImg);
					breakFlag = 1;//传递打破循环的信息
					break;
				case 2:
					save();//保存信息
					exit(-1);//退出游戏
					break;
				default:
					break;
				}
				break;
			case ESC:
				putimage(240, 160, &pauseImg);
				breakFlag = 1;//传递打破循环的信息
				break;
			}
		}
		if (breakFlag)
			break;//选择继续游戏则打破WHILE循环
	}
}

void PauseChoiceButton(int PauseChoice) {//打印选项按钮
	switch (PauseChoice){
	case 1:
		setfillcolor(RED);
		fillcircle(275, 200, 10);
		setfillcolor(WHITE);
		fillcircle(275, 280, 10);
		break;
	case 2:
		setfillcolor(WHITE);
		fillcircle(275, 200, 10);
		setfillcolor(RED);
		fillcircle(275, 280, 10);
		break;
	}
}

/**绘制死亡画面*/
void PrintEnd() {
	IMAGE endImg;
	loadimage(&endImg, _T("..\\res\\ending.jpg"), 640, 390);
	putimage(0, 45, &endImg);
	Sleep(1000);
	settextcolor(WHITE);
	settextstyle(30, 0, _T("微软雅黑"));
	outtextxy(230, 350, _T("按任意键继续"));
	_getch();
}

void PrintMissionINFO() {
	setfillcolor(WHITE);
	fillroundrect(0, 150, 80, 350, 2, 2);
	switch (Mission) {
	case MISSION1:
		settextstyle(15,7,_T("黑体"));
		setbkcolor(WHITE);
		settextcolor(BLUE);
		outtextxy(10, 200, _T("水晶地宫"));
		settextcolor(BLACK);
		outtextxy(10, 250, _T("关卡目标:"));
		settextcolor(RED);
		outtextxy(10, 300, _T("获得5K分!"));
		break;
	case MISSION2:
		settextstyle(15, 7, _T("黑体"));
		setbkcolor(WHITE);
		settextcolor(RED);
		outtextxy(10, 200, _T("山行如墨"));
		settextcolor(BLACK);
		outtextxy(10, 250, _T("关卡目标:"));
		settextcolor(RED);
		outtextxy(10, 300, _T("获得2W分!"));
		break;
	case MISSION3:
		settextstyle(15, 7, _T("黑体"));
		setbkcolor(WHITE);
		settextcolor(YELLOW);
		outtextxy(10, 200, _T("深海轮回"));
		settextcolor(GREEN);
		outtextxy(10, 250, _T("关卡目标:"));
		settextcolor(RED);
		outtextxy(10, 300, _T("生存&刷分"));
		break;
	}
}
/**实时得分显示*/
void PrintMark() {//游戏过程中旁边显示的分数
	settextstyle(16,9, _T("黑体"));
	setbkcolor(BLACK);
	setfillcolor(BLACK);
	fillroundrect(570, 150, 630, 350, 5, 5);
	settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));
	outtextxy(580, 200, _T("SCORE"));
	TCHAR tmark[20];
	_itow_s(mark,tmark,10);
	outtextxy(580, 230, tmark);
	settextcolor(WHITE);
	outtextxy(580, 260, _T("蛇长:"));
	TCHAR tlen[3];
	_itow_s(len, tlen, 10);
	outtextxy(580, 280, tlen);
}

void PrintMarkINFO() {
	setfillcolor(BLACK);
	solidrectangle(0, 0, 640, 480);
	settextcolor(WHITE);
	gettextstyle(&f);
	settextstyle(28, 12, _T("Comic Sans MS"));
	outtextxy(240, 100, _T("您本次得分为:"));
	TCHAR tmark[10];
	_itow_s(mark, tmark, 10);
	outtextxy(300, 160, tmark);
	outtextxy(240, 300, _T("感谢您的游玩!"));
	outtextxy(220, 380, _T("按ESC键回到主菜单"));
	settextstyle(&f);
	PrintStarSky();
}
/**绘制游戏主界面*/
void PrintMapINFO() {
	//绘制包括地图和障碍物
	switch (Mission) {
	case MISSION1:
		loadimage(NULL, _T("..\\res\\Map1.jpg"), 640, 480, true);
		break;
	case MISSION2:
		loadimage(NULL, _T("..\\res\\Map2.jpg"), 640, 480, true);
		break;
	case MISSION3:
		loadimage(NULL, _T("..\\res\\Map3.jpg"), 640, 480, true);
		break;
	}
	pbWnd = GetImageBuffer();
	SetBarINFO();
	//DefaultMap();
}

void PrintRankList() {
	setfillcolor(BLACK);
	solidrectangle(0, 0, 640, 480);
	PlayerInfo bestplayer = loadRankINFO();
	if (bestplayer.PlayerMark != 0) {
		settextcolor(YELLOW);
		outtextxy(240, 150, _T("地 表 最 强"));
		TCHAR tmark[10];
		_itow_s(bestplayer.PlayerMark,tmark,10);
		settextstyle(30, 14, _T("Comic Sans MS"));
		settextcolor(WHITE);
		TCHAR Tbestplayer[6];
		MultiByteToWideChar(CP_ACP, 0, bestplayer.name, strlen(bestplayer.name), Tbestplayer, 6);
		outtextxy(240, 220, Tbestplayer);
		outtextxy(240, 300, tmark);
	}
	else {
		settextcolor(WHITE);
		settextstyle(40, 22, _T("微软雅黑"));
		outtextxy(220, 220, _T("虚 位 以 待"));
	}
	PrintStarSky();
}

void PrintMissionSuccessINFO() {
	switch (Mission) {
	case MISSION1:
		setfillcolor(BLACK);
		solidrectangle(0, 0, 640, 480);
		settextcolor(WHITE);
		settextstyle(28, 12, _T("Comic Sans MS"));
		outtextxy(240, 100, _T("Congratulations!"));
		settextcolor(YELLOW);
		outtextxy(240, 200, _T("恭喜您通过了第一关!"));
		settextcolor(WHITE);
		outtextxy(250, 400, _T("按ESC回到选单"));
		break;
	case MISSION2:
		setfillcolor(BLACK);
		solidrectangle(0, 0, 640, 480);
		settextcolor(WHITE);
		settextstyle(28, 12, _T("Comic Sans MS"));
		outtextxy(240, 100, _T("Congratulations!"));
		settextcolor(YELLOW);
		outtextxy(240, 200, _T("恭喜您通过了第二关!"));
		settextcolor(WHITE);
		outtextxy(250, 400, _T("按ESC回到选单"));
		break;
	}

	PrintStarSky();
}

void PrintAuthorINFO() {
	setfillcolor(BLACK);
	solidrectangle(0, 0, 640, 480);
	gettextstyle(&f);//得到默认字体将其存入LOGFONT f
	settextcolor(WHITE);
	settextstyle(28,12,_T("Comic Sans MS"));
	outtextxy(240, 150, _T("作者:  陈立伟"));
	outtextxy(240, 250, _T("游戏版本: v1.0"));
	outtextxy(240, 350, _T("感谢您的游玩!!!"));
	settextstyle(&f);//改回默认字体
	PrintStarSky();
}

void PrintStarSky() {
	struct STAR {
		double x;
		int y;
		double step;
		int color;
	};
	STAR star[256];
	for (int i = 0;i < 256;i++) {
		star[i].x = rand() % 640;
		star[i].y = rand() % 480;
		star[i].step = (rand() % 5000) / 1000.0 + 1;
		star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
		star[i].color = RGB(star[i].color, star[i].color, star[i].color);
	}
	srand((UINT)GetCurrentTime());
	while (TRUE) {
		for (int i = 0;i < 256;i++) {
				// 擦掉原来的星星
				putpixel((int)star[i].x, star[i].y, 0);

				// 计算新位置
				star[i].x += star[i].step;
				if (star[i].x > 640) {
					star[i].x = rand() % 640;
					star[i].y = rand() % 480;
					star[i].step = (rand() % 5000) / 1000.0 + 1;
					star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
					star[i].color = RGB(star[i].color, star[i].color, star[i].color);
				}

				// 画新星星
				putpixel((int)star[i].x, star[i].y, star[i].color);

			}
		if(_kbhit()){
			int key = _getch();
			if (key == ESC)
				break;
			}
		Sleep(20);
	}
}

void setDefaultMap() {
	switch (Mission) {
	case MISSION1:
		loadimage(&defaultImg, _T("..\\res\\Map1.jpg"), 640, 480);
		pDeMap = GetImageBuffer(&defaultImg);
		break;
	case MISSION2:
		loadimage(&defaultImg, _T("..\\res\\Map2.jpg"), 640, 480);
		pDeMap = GetImageBuffer(&defaultImg);
		break;
	case MISSION3:
		loadimage(&defaultImg, _T("..\\res\\Map3.jpg"), 640, 480);
		pDeMap = GetImageBuffer(&defaultImg);
		break;
	}

}

/**绘制蛇身*/
void SetSnakeINFO() {
	IMAGE snakeImg;
	loadimage(&snakeImg, _T("..\\res\\Snake.jpg"), 640, 480);
	DWORD* psImg = GetImageBuffer(&snakeImg);
	node* p = head;
	int r, g, b, k;
		do {
			int StartX = 80 + CELLWIDTH * p->cor.X;
			int EndX = 80 + CELLWIDTH * (p->cor.X + 1);
			int StartY = CELLHEIGHT * p->cor.Y;
			int EndY = CELLHEIGHT * (p->cor.Y + 1);
			for (int i = StartX;i < EndX;i++) {
				for (int j = StartY;j < EndY;j++) {
					k = i + 640 * j;
					r = (int)GetRValue(psImg[k]);
					g = (int)GetGValue(psImg[k]);
					b = (int)GetBValue(psImg[k]);
					pbWnd[k] = RGB(r, g, b);
				}
			}
			p = p->next;
		} while (p != NULL);
}

/**绘制食物*/
void SetFoodINFO() {
	IMAGE foodImg;
	loadimage(&foodImg, _T("..\\res\\Food.jpg"),640,480);
	DWORD* pfImg = GetImageBuffer(&foodImg);
	int r, g, b, k;
	int StartX = 80 + CELLWIDTH* Food.X;
	int EndX = 80 + CELLWIDTH*(Food.X + 1);
	int StartY = CELLHEIGHT*Food.Y;
	int EndY = CELLHEIGHT*(Food.Y + 1);
	for (int i = StartX;i < EndX;i++) {
		for (int j = StartY;j < EndY;j++) {
			k = i + 640 * j;
			r = (int)GetRValue(pfImg[k]);
			g = (int)GetGValue(pfImg[k]);
			b = (int)GetBValue(pfImg[k]);
			pbWnd[k] = RGB(r, g, b);
		}
	}

}

/**绘制地雷*/
void SetBombINFO() {
	int StartX = 0, EndX = 0, StartY = 0, EndY = 0;
	setfillcolor(RED);
	BeginBatchDraw();
	for (int i = 0;i < 25;i++) {
		if (Bomb[i].X != 0 && Bomb[i].Y != 0) {
			StartX = 80 + CELLWIDTH*Bomb[i].X;
			EndX = StartX + CELLWIDTH;
			StartY = CELLHEIGHT*Bomb[i].Y;
			EndY = StartY + CELLHEIGHT;
			fillroundrect(StartX, StartY, EndX - 1, EndY - 1, 1, 1);
		}
	}
	EndBatchDraw();
}

void SetPoisonINFO() {
	setfillcolor(RGB(rand()%256,rand()%256,rand()%256));
	BeginBatchDraw();
	int StartX, EndX, StartY, EndY;
	for (int i = 0;i < 50;i++) {
		if (Poison[i].X != 0 && Poison[i].Y != 0) {
			StartX = 80 + CELLWIDTH*Poison[i].X;
			EndX = StartX + CELLWIDTH;
			StartY = CELLHEIGHT*Poison[i].Y;
			EndY = StartY + CELLHEIGHT;
			fillellipse(StartX, StartY, EndX-1, EndY-1);
		}
	}
	EndBatchDraw();
}

void SetWiseGrassINFO() {
	if (WiseGrass.X != 0 && WiseGrass.Y != 0) {
		setfillcolor(YELLOW);
		int StartX = 80 + CELLWIDTH*WiseGrass.X;
		int EndX = StartX + CELLWIDTH;
		int StartY = CELLHEIGHT*WiseGrass.Y;
		int EndY = StartY + CELLHEIGHT;
		fillroundrect(StartX, StartY, EndX, EndY, 1, 1);
	}
}
/**绘制障碍物*/
void SetBarINFO() {
	int StartX, StartY, EndX, EndY;
	for (int i = 0;i < BarLen;i++) {
		StartX = 80 + CELLWIDTH*Bar[i].X;
		StartY = CELLHEIGHT*Bar[i].Y;
		EndX = StartX + CELLWIDTH;
		EndY = StartY + CELLHEIGHT;
		solidrectangle(StartX, StartY, EndX, EndY);
	}
}

/**移动光标至指定坐标，达到局部刷新蛇头或蛇身的目的*/
void gotoxy(COORD pt) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pt);
}

/**隐藏光标，不致使光标影响游戏体验*/
void HideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//设置新的光标信息，将光标改为不可视
	/**typedef struct{ 
			DWORD dwSize;
			 BOOL bVisible; //为0时光标不可见
		}CONSOLE_CURSOR_INFO,  *PCONSOLE_CURSOR_INFO;CONSOLE_CURSOR_INFO结构体在API中的定义*/
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	//将新的光标信息送入
}

void SetAll() {
	SetSnakeINFO();
	SetFoodINFO();
	SetBombINFO();
	SetPoisonINFO();
	SetWiseGrassINFO();
	FlushBatchDraw();
	PrintMark();
}

void localRefresh(COORD Tcor) {//该函数还要更改(适应地雷炸掉半截身体)
	int StartX = 80+ CELLWIDTH*Tcor.X;
	int StartY = CELLHEIGHT*Tcor.Y;
	int EndX = StartX + CELLWIDTH;
	int EndY = StartY + CELLHEIGHT;
	int k = 0;
	for (int i = StartX;i < EndX;i++) {
		for (int j = StartY;j < EndY;j++) {
			k = i + 640 * j;
			pbWnd[k] = pDeMap[k];
		}
	}
}
