#include<stdio.h>
#include<string.h>
int main() {
	int m, n;
	printf("��������������\n");
	scanf_s("%d", &n);
	printf("������ÿ�γ�Ȧ�Ĵ���\n");
	scanf_s("%d", &m);
	//��ʼ�����飬��ÿ��ֵ��Ϊ0
	int a[100] = { 0 };
	int i, j, k = 0;
	//��ʼ�����飬�������n����������������=���-1��
	for (i = 0;i < n;i++) a[i] = i + 1;
	//��ֻʣһ����ʱ��Ȼ�����ж�
	while (n > 1) 
	{
		i = (i + m - 1) % n;
		k++;
		printf("��%d����Ȧ���ǣ�%d\n", k, a[i]);
		for (j = i + 1;j < n;j++) a[j - 1] = a[j];
		n--;
		if (i == n) i = 0;
	}
	printf("���ʣ�µ���%d\n", a[i]);
	return 0;
}