#include<stdio.h>
int main() {
	int a[10][10] = {0};
	int i, j, k;
	a[0][0] = 1;
	//外层i控制行数(从第二行起算)
	for (i = 1;i < 10;i++) {
		a[i][0] = 1;//初始化每一行第一个元素为1
		for (j = 1;j <= i;j++) {
			//从每行第二个起算，每个都是上一行的索引-1数和相同索引数的和
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0;i < 10;i++) {
		for (j = 0;j <= i;j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
