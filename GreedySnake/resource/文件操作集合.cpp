#include"vardefine.h" 

FILE* mem;
errno_t err;
COORD snake[200];

void save() {
	node* p = NULL;
	if ((err = fopen_s(&mem, "sav.txt", "w+")) == NULL) {
		fwrite(&len, sizeof(len), 1, mem);
		fwrite(&mark, sizeof(mark), 1, mem);
		fwrite(&currentDirection, sizeof(currentDirection), 1, mem);
		fwrite(&Food, sizeof(Food), 1, mem);
		fwrite(Bomb, sizeof(COORD), 25, mem);
		fwrite(Poison, sizeof(COORD), 50, mem);
		fwrite(&WiseGrass, sizeof(WiseGrass), 1, mem);
		fwrite(&Mission, sizeof(Mission), 1, mem);
		for (int i = 0;i < BarLen;i++)
			fwrite(&Bar[i], sizeof(Bar[i]), 1, mem);
		for (p = head;p != NULL;p = p->next)
			fwrite(&(p->cor), sizeof(p->cor), 1, mem);
		fclose(mem);
	}
	//可加弹窗提示
}

void load() {
	node *p, *q;
	int i, j;
	if ((err = fopen_s(&mem, "sav.txt", "r")) == NULL) {
		fread(&len, sizeof(len), 1, mem);
		fread(&mark, sizeof(mark), 1, mem);
		fread(&currentDirection, sizeof(currentDirection), 1, mem);
		fread(&Food, sizeof(Food), 1, mem);
		fread(Bomb, sizeof(COORD), 25, mem);
		fread(Poison,sizeof(COORD), 50, mem);
		fread(&FoodNum, sizeof(FoodNum), 1, mem);
		fread(&WiseGrass, sizeof(WiseGrass), 1, mem);
		fread(&Bar, sizeof(COORD), BarLen, mem);//读取存储的障碍物坐标
		fread(snake, sizeof(COORD), len, mem);//读取存储在文件中的len个长度的蛇坐标集合
		fread(&Mission, sizeof(Mission), 1, mem);
		fclose(mem);
	}
	else {
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, TEXT("您未有任何存档！"), TEXT("提示"), MB_OK|MB_ICONWARNING);
	}
	//重新建立链表
	p = head = (node*)malloc(sizeof(node));
	p->cor = snake[0];
	for (i = 1;i < len;i++) {
		q = (node*)malloc(sizeof(node));
		q->cor = snake[i];
		q->previous = p;
		p->next = q;
		p = p->next;
	}
	p->next = NULL;//蛇尾的指针域指向下一节的置空
}
 
void saveRankINFO(PlayerInfo pi) {
	if ((err = fopen_s(&mem, "RankList.txt", "w+")) == NULL) {
		fwrite(&pi, sizeof(PlayerInfo), 1, mem);
		fclose(mem);
	}
	else {
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, TEXT("保存信息失败"), TEXT("鬼知道出啥幺蛾子了"), MB_OK | MB_ICONWARNING);
	}
}

PlayerInfo loadRankINFO() {
	PlayerInfo loadpi = {"NULL",0};
	if ((err = fopen_s(&mem, "RankList.txt", "r")) == NULL) {
		fread(&loadpi, sizeof(PlayerInfo), 1, mem);
		fclose(mem);
	}
	return loadpi;
}

void LoadGame() {
	load();
}