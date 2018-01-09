#include"vardefine.h"
/**采用了双向链表，通常只是对蛇尾进行内存释放*/



//判断是否吃到食物
int isFood() {
	if (Cor_Cmp(Food, head->cor)) {
		FoodFlag = 1;
		return 1;
	}
	else if (Bomb_Cmp(head->cor)) {
		FoodFlag = 2;
		return 1;
	}
	else if (Poison_Cmp(head->cor)) {
		FoodFlag = 3;
		return 1;
	}
	else if(Cor_Cmp(WiseGrass, head->cor)) {
		FoodFlag = 4;
		return 1;
	}
	else {
		return 0;//都不重合返回0
	}

	
}

//不管怎样移动，头部都要增加一个节点
void AddHeadNode() {
	node *newH = (node*)malloc(sizeof(node));//为新头开辟存储空间
	newH->cor = head->cor;
	newH->previous = NULL;//新头的头的上一节置空
	newH->next = head;//让新头的指向下一节的指针链到旧头
	head->previous = newH;//旧头的指向上一节的指针链到新头
	head = newH;//将新头的地址赋给总头的地址(只记录头的位置)
}

//没吃到食物时会有删除尾节点的操作
void CutTailNode() {
	node *p = head, *t = NULL;
	for (p;p->next->next != NULL;p = p->next);//循环找到蛇身的倒数第二节(它的下下节为空)
	t = p->next;//找到蛇尾
	localRefresh(t->cor);//把蛇尾遮盖的地图显示出来
	p->next = NULL;//切断旧蛇尾与前一节的联系
	//free(t);不知为何会报错...
}
