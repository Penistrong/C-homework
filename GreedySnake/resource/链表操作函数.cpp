#include"vardefine.h"
/**������˫������ͨ��ֻ�Ƕ���β�����ڴ��ͷ�*/



//�ж��Ƿ�Ե�ʳ��
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
		return 0;//�����غϷ���0
	}

	
}

//���������ƶ���ͷ����Ҫ����һ���ڵ�
void AddHeadNode() {
	node *newH = (node*)malloc(sizeof(node));//Ϊ��ͷ���ٴ洢�ռ�
	newH->cor = head->cor;
	newH->previous = NULL;//��ͷ��ͷ����һ���ÿ�
	newH->next = head;//����ͷ��ָ����һ�ڵ�ָ��������ͷ
	head->previous = newH;//��ͷ��ָ����һ�ڵ�ָ��������ͷ
	head = newH;//����ͷ�ĵ�ַ������ͷ�ĵ�ַ(ֻ��¼ͷ��λ��)
}

//û�Ե�ʳ��ʱ����ɾ��β�ڵ�Ĳ���
void CutTailNode() {
	node *p = head, *t = NULL;
	for (p;p->next->next != NULL;p = p->next);//ѭ���ҵ�����ĵ����ڶ���(�������½�Ϊ��)
	t = p->next;//�ҵ���β
	localRefresh(t->cor);//����β�ڸǵĵ�ͼ��ʾ����
	p->next = NULL;//�жϾ���β��ǰһ�ڵ���ϵ
	//free(t);��֪Ϊ�λᱨ��...
}
