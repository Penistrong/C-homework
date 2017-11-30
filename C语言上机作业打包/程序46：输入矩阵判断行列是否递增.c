#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[3][3];//设置一个3X3二维数组
	int i, j, h;
	void Check(int b[][3]);//定义检查行列是否递增的函数
	for (i = 0;i <= 2;i++) {
		h = i + 1;
		printf("请输入第%d行第1个数:\n",h);
		for (j=0;j <= 2;j++) {
			scanf_s("%d", &a[i][j]);
			if (j < 2)
				printf("请输入下一个数:\n");
		}
	}
	//打印矩阵
	printf("您输入的矩阵如下:\n");
	for (i = 0;i <= 2;i++) {
		for (j = 0;j <= 2;j++) {
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	Check(a[3][3]);
	system("pause");
	return 0;
}
void Check(int b[][3]) {
	int i, h, l;//h,l分别表示行，列
	//判断每行是否递增
	for (i = 0;i <= 2;i++) {
		h = i + 1;
		if (b[i][0] < b[i][1] && b[i][1] < b[i][2])
			printf("第%d行是递增的\n", h);
		else
			printf("第%d行不递增\n", h);
	}
	//判断每列是否递增
	for (i = 0;i <= 2;i++) {
		l = i + 1;
		if (b[0][i] < b[1][i] && b[1][i] < b[2][i])
			printf("第%d列是递增的\n", l);
		else
			printf("第%d列不递增\n", l);
	}
}