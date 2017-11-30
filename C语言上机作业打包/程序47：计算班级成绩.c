#include<stdio.h>
int main() {
	double a[4][5] = {0};
	int i, j, temp;
	printf("请依次输入学生的四科成绩，每门成绩用逗号隔开：\n");
	for (i = 0;i < 3;i++) {
		j = i + 1;
		printf("请输入第%d个学生的四科成绩：\n",j);
		scanf_s("%lf,%lf,%lf,%lf", &a[i][0], &a[i][1],&a[i][2], &a[i][3]);
	}
	for (i = 0;i < 3;i++) {
		a[i][4] = (a[i][0] + a[i][1] + a[i][2] + a[i][3]) /4;
	}
	for (j = 0;j < 5;j++) {
		a[3][j] = (a[0][j] + a[1][j] + a[2][j]) / 3;
	}
	for (i = 0;i < 4;i++) {
		temp = i + 1;
		if (i <= 2) {
			printf("学生%d成绩：\t", temp);
		}
		else {
			printf("班级总成绩：\t");
		}
		
		for (j = 0;j < 5;j++) {
			printf("%.1lf\t", a[i][j]);
		}
		printf("\n");
	}
	return 0;

}