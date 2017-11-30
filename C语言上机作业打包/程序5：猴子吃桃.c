#include<stdio.h>
void main() {
	int i,sum;
	sum = 0;
	for (i = 1;i <= 9;i++) {
		sum = (sum + 1) * 2;
	}
	printf("猴子第一天摘了%d个桃子\n", sum);
}