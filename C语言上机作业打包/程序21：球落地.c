#include<stdio.h>
void main() {
	int n,i;
	double M = 100,sum = 0,temp = 0;
	printf("请输入球落地的次数：\n");
	scanf_s("%d", &n);
	if (n <= 0) printf("您输入的次数非法！");
	for (i = 1;i <= n;i++) {
		sum = sum + M + temp;
		temp = M / 2;
		M = M / 2;
		if (i == n) {
			printf("到第%d次落地时，共经过了%lf米\n",n,sum);
			printf("第%d次将反弹%lf米", n, temp);
		}
	}
}
