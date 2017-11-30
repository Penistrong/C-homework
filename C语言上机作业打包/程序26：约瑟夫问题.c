#include<stdio.h>
#include<string.h>
int main() {
	int m, n;
	printf("请输入总人数：\n");
	scanf_s("%d", &n);
	printf("请输入每次出圈的次序：\n");
	scanf_s("%d", &m);
	//初始化数组，让每个值都为0
	int a[100] = { 0 };
	int i, j, k = 0;
	//初始化数组，让输入的n个人依次排序（索引=序号-1）
	for (i = 0;i < n;i++) a[i] = i + 1;
	//当只剩一个人时自然不用判断
	while (n > 1) 
	{
		i = (i + m - 1) % n;
		k++;
		printf("第%d个出圈的是：%d\n", k, a[i]);
		for (j = i + 1;j < n;j++) a[j - 1] = a[j];
		n--;
		if (i == n) i = 0;
	}
	printf("最后剩下的是%d\n", a[i]);
	return 0;
}