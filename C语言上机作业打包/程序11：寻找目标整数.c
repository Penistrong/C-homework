#include<stdio.h>
#include<math.h>
void main() {
	int i, a, b;
	for (i = 1;i <= 100000;i++) {
		a = sqrt(i + 100);
		b = sqrt(i + 268);
		if (a*a==(i+100)&&b*b==(i+268)){
			printf("已找到该数：%d\n", i);
		}
	}
}