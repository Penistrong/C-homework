#include<stdio.h>
#include<string.h>
int main() {
	int binsearch(int x, int v[], int n);
	int i, x, n, v[1000];
	char a[1000];
	printf("请输入数据流：(只能以升序排列)\n");
	scanf_s("%s", a, 1000);
	n = strlen(a);
	printf("请输入您想要比对的值：\n");
	scanf_s("%d", &x);
	for (i = 0;i < n - 1;i++) {
		v[i] = a[i] - '0';
	}
	int result = binsearch(x, v[], n);
}

int binsearch(int x, int v[], int n) {
	int low, mid, high;
	low = 0;
	high = n - 1;//索引最大值
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /*找到了匹配的值*/
			return mid;
	}
	return -1;/*没有匹配的值*/
}