#include"vardefine.h"

void FoodType() {
	switch (FoodFlag) {
	case DELICIOUS:
		eatFood();
		break;
	case BOMB:
		eatBomb();
		break;
	case POISON:
		eatPoison();
		break;
	case GRASS:
		eatWiseGrass();
		break;
	}
}

void eatFood() {
	FoodNum++;
	len++;
	mark += 100;//�Ե�ʳ���100��
	Food = getFoodCor();//������һ��ʳ��
}

void eatBomb(){
	if (len <= 2) {
		FoodNum++;
		gameRes = 0;//�߳�С��3�ڶ��ᵼ������
	}
	else {
		FoodNum++;
		mark += 250;//�Ե��׼�250��
		len = len / 2;
		node* p = NULL;
		int counter = 0;
		for (p = head;p != NULL;p = p->next) {
			counter++;
			if (counter == len) {//�ҵ��ϵ�һ������β��һ��
				node* pn = p;
				do{
					localRefresh(pn->next->cor);//��ը����һ�������ڸǵĵ�ͼ��ʾ����
					pn = pn->next;
				} while (pn->next != NULL);
				p->next = NULL;//�ж�
				break;
			}
		}
	}
}

void eatPoison() {
	FoodNum++;
	len--;//�Ե����ݳ��ȼ�һ
	mark -= 50;//�Զ��ݼ�50��
	if (len == 1||len == 0) {
		gameRes = 0;
	}else {
		CutTailNode();
		CutTailNode();//�����������Σ����߼�ɾ������β������β��Ӧ
	}
}

void eatWiseGrass() {
	FoodNum++;
	WiseGrass = { 0,0 };//�����ǻ۲�������Ϣ
	//�Ե��ǻ۲�ʱ�Զ�Ѱ·(������)
	len++;
	mark += 1000;
}

void spawnDiff() {
	if (FoodNum % 10 == 0) {
		int flag;
		PoisonStartTime = time(NULL);
		PoisonExist = 1;//���ö��ݴ���Ϊtrue
		//ÿ��10������һ�Ѷ���(ÿ�����ɶ�����ϴε���Ϣ)
		for (int i = 0;i < 50;i++) {
			if (Poison[i].X != 0 && Poison[i].Y != 0) {
				localRefresh(Poison[i]);
			}
		}
		FlushBatchDraw();
		for (int i = 0;i < 50;i++) {
			do {
				flag = 0;
				Poison[i] = getFoodCor();
				if (Cor_Cmp(WiseGrass, Poison[i]))
					flag = 1;
				for (int j = 0;j < 25;j++) {
					flag = Cor_Cmp(Bomb[i], Poison[i]);
					if (flag == 1)
						break;
				}
			} while (flag);//�����/�ǻ۲��غ�ʱ��������
		}
	}
	else if (FoodNum % 6 == 0) {
		int flag;
		//ÿ��6������һ�ѵ���(���ɵ���ʱ�����ϴ����ɵĵ���)
		for (int i = 0;i < 25;i++) {
			if (Bomb[i].X != 0 && Bomb[i].Y != 0) {
				localRefresh(Bomb[i]);
			}
		}
		FlushBatchDraw();
		for (int i = 0;i < 25;i++) {
			do {
				flag = 0;
				Bomb[i] = getFoodCor();
				if (Cor_Cmp(WiseGrass, Bomb[i]))
					flag = 1;
				for (int j = 0;j < 50;j++) {
					flag = Cor_Cmp(Bomb[i], Poison[i]);
					if (flag == 1)
						break;
				}
			} while (flag);
		}
	}
	else if (FoodNum % 15 == 0) {
		int flag;
		if (WiseGrass.X != 0 && WiseGrass.Y != 0) {
			localRefresh(WiseGrass);
			FlushBatchDraw();
		}
		//ÿ��15������һ���ǻ۲�
		do {
			flag = 0;
			WiseGrass = getFoodCor();
			for (int i = 0;i < 25;i++) {
				if (Cor_Cmp(Bomb[i], WiseGrass)) {
					flag = 1;
					break;
				}	
			}
			for (int j = 0;j < 50;j++) {
				if (Cor_Cmp(Poison[j], WiseGrass)) {
					flag = 1;
					break;
				}
			}
		} while (flag);
	}
}

void clearPoison() {
	if (PoisonExist) {
		PoisonEndTime = time(NULL);
		if (difftime(PoisonEndTime,PoisonStartTime) >= 5) {
			for (int i = 0;i < 50;i++) {
				if (Poison[i].X != 0 && Poison[i].Y != 0) {
					localRefresh(Poison[i]);
					Poison[i].X = 0;
					Poison[i].Y = 0;
				}
			}
			FlushBatchDraw();
			PoisonExist = 0;//���������
		}
	}
}