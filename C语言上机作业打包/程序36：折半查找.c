#include<stdio.h>
#include<string.h>
int main() {
	int binsearch(int x, int v[], int n);
	int i, x, n, v[1000];
	char a[1000];
	printf("��������������(ֻ������������)\n");
	scanf_s("%s", a, 1000);
	n = strlen(a);
	printf("����������Ҫ�ȶԵ�ֵ��\n");
	scanf_s("%d", &x);
	for (i = 0;i < n - 1;i++) {
		v[i] = a[i] - '0';
	}
	int result = binsearch(x, v[], n);
}

int binsearch(int x, int v[], int n) {
	int low, mid, high;
	low = 0;
	high = n - 1;//�������ֵ
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /*�ҵ���ƥ���ֵ*/
			return mid;
	}
	return -1;/*û��ƥ���ֵ*/
}