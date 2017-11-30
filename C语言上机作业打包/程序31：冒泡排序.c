#include<stdio.h>
#include<string.h>
int main() {
	int a[10] = { 3,12,56,23,98,45,46,35,47,65 };
	for (int n = 0;n < 10;n++) {
		printf("%d\t", a[n]);
	}
	//外层为大循环，判断需要比较的轮数(次数等于长度减1)
	for (int i = 0;i < 9;i++) {
		//内层为内循环，k的最大值为每轮需要比较的次数(次数等于长度减轮序减1)
		for (int k = 0;k < (10-i-1);k++) {
			if (a[k+1] > a[k]) {
				int temp = a[k + 1];
				a[k + 1] = a[k];
				a[k] = temp;
			}
		}
	}
	printf("\n");
	for (int j = 0;j <= 9;j++) {
		printf("%d\t", a[j]);
	}
}