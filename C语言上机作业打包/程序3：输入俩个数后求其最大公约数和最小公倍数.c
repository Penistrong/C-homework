#include<stdio.h>
void main() {
	printf("please input two numbers:\n");
	int m, n;
	scanf_s("%d%d", &m, &n);
	int min = m;
	int max = n;
	if (n < m) {
		min = n;
		max = m;
	}
	for (min;min >= 1;min--) {
		if ((m%min == 0) && (n%min == 0)) {
			printf("���Լ����%d\n", min);
			break;
		}
	}
	for (max;max <=(m*n);max++) {
		if ((max%m == 0) && (max%n == 0)) {
			printf("��С��������%d\n", max);
			break;
		}
	}



}