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
	mark += 100;//吃到食物加100分
	Food = getFoodCor();//产生下一个食物
}

void eatBomb(){
	if (len <= 2) {
		FoodNum++;
		gameRes = 0;//蛇长小于3节都会导致死亡
	}
	else {
		FoodNum++;
		mark += 250;//吃地雷加250分
		len = len / 2;
		node* p = NULL;
		int counter = 0;
		for (p = head;p != NULL;p = p->next) {
			counter++;
			if (counter == len) {//找到断掉一半后的蛇尾那一节
				node* pn = p;
				do{
					localRefresh(pn->next->cor);//把炸掉的一半身体遮盖的地图显示出来
					pn = pn->next;
				} while (pn->next != NULL);
				p->next = NULL;//切断
				break;
			}
		}
	}
}

void eatPoison() {
	FoodNum++;
	len--;//吃到毒草长度减一
	mark -= 50;//吃毒草减50分
	if (len == 1||len == 0) {
		gameRes = 0;
	}else {
		CutTailNode();
		CutTailNode();//连续调用两次，与逻辑删除旧蛇尾与新蛇尾对应
	}
}

void eatWiseGrass() {
	FoodNum++;
	WiseGrass = { 0,0 };//重置智慧草坐标信息
	//吃到智慧草时自动寻路(待完善)
	len++;
	mark += 1000;
}

void spawnDiff() {
	if (FoodNum % 10 == 0) {
		int flag;
		PoisonStartTime = time(NULL);
		PoisonExist = 1;//设置毒草存在为true
		//每吃10个生成一堆毒草(每次生成都清空上次的信息)
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
			} while (flag);//与地雷/智慧草重合时重新生成
		}
	}
	else if (FoodNum % 6 == 0) {
		int flag;
		//每吃6个生成一堆地雷(生成地雷时擦掉上次生成的地雷)
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
		//每吃15个生成一个智慧草
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
			PoisonExist = 0;//满足后重置
		}
	}
}