#include<stdio.h>
void main() {
	int n,i;
	double M = 100,sum = 0,temp = 0;
	printf("����������صĴ�����\n");
	scanf_s("%d", &n);
	if (n <= 0) printf("������Ĵ����Ƿ���");
	for (i = 1;i <= n;i++) {
		sum = sum + M + temp;
		temp = M / 2;
		M = M / 2;
		if (i == n) {
			printf("����%d�����ʱ����������%lf��\n",n,sum);
			printf("��%d�ν�����%lf��", n, temp);
		}
	}
}
