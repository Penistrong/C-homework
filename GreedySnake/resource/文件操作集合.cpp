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
	//�ɼӵ�����ʾ
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
		fread(&Bar, sizeof(COORD), BarLen, mem);//��ȡ�洢���ϰ�������
		fread(snake, sizeof(COORD), len, mem);//��ȡ�洢���ļ��е�len�����ȵ������꼯��
		fread(&Mission, sizeof(Mission), 1, mem);
		fclose(mem);
	}
	else {
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, TEXT("��δ���κδ浵��"), TEXT("��ʾ"), MB_OK|MB_ICONWARNING);
	}
	//���½�������
	p = head = (node*)malloc(sizeof(node));
	p->cor = snake[0];
	for (i = 1;i < len;i++) {
		q = (node*)malloc(sizeof(node));
		q->cor = snake[i];
		q->previous = p;
		p->next = q;
		p = p->next;
	}
	p->next = NULL;//��β��ָ����ָ����һ�ڵ��ÿ�
}
 
void saveRankINFO(PlayerInfo pi) {
	if ((err = fopen_s(&mem, "RankList.txt", "w+")) == NULL) {
		fwrite(&pi, sizeof(PlayerInfo), 1, mem);
		fclose(mem);
	}
	else {
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, TEXT("������Ϣʧ��"), TEXT("��֪����ɶ�۶�����"), MB_OK | MB_ICONWARNING);
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