#include<stdio.h>
int n , days;//����ȫ�ֱ��������������ʣ�µ�������n������days
int main() {
	int Calculate(int n);
	printf("��������ӳ��ҵ�����(���������Ĵ��������ܼ�����)��\n");
	scanf_s("%d",&days);
	printf("��������ӵ�%d������ʣ�µ����ӣ�\n",days);
	scanf_s("%d", &n);
	int sum;
	sum = Calculate(1);
	printf("���ӵ�һ��һ��ժ�� %d ������", sum);
	getchar();
	return 0;
}
//iΪ������ʱ��
int Calculate(int i) {
	if (i < days)
		return 2 * (Calculate(i + 1) + 1);//ÿ�εݹ����ýڵ㣬һֱ�ȴ����һ������
	else if (i == days)//��������ʱ���ﵽ�������ʱ��ֻʣn������
		return n;
	else
		return -1;//-1��ʾ�쳣
}