#include<stdio.h>
void main() {
	int i,sum;
	sum = 0;
	for (i = 1;i <= 9;i++) {
		sum = (sum + 1) * 2;
	}
	printf("���ӵ�һ��ժ��%d������\n", sum);
}