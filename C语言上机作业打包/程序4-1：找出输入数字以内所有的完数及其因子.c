#include<stdio.h>
void main() {
	int p[80];
	int n, i, count, temp, sum = 0;
	int Maxnum;
	printf("请输入您所要寻找的范围上限：");
	scanf_s("%d",&Maxnum);
	for (n = 2;n < Maxnum;n++) {
		count = 0;
		temp = n;
		for (i = 1;i <= n - 1;i++) {
			if (n%i == 0) {
				//计数器自增（标记因子数量）并将因子保存进数组,
				p[count++] = i;
				//减掉这个因子，循环直到temp等于0，意即减掉因子的和等于原数
				temp -= i;
			}
		}
		if (temp == 0) {
			printf("%4d是一个完数，因子有；", n);
			printf("%d = %d", n, p[0]);
			for (i = 1;i < count;i++) {
				printf("+ %d", p[i]);
			}
			printf("\n");
			sum++;
		}
	}	
	printf("共有%d个完数\n", sum);
}