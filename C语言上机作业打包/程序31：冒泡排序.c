#include<stdio.h>
#include<string.h>
int main() {
	int a[10] = { 3,12,56,23,98,45,46,35,47,65 };
	for (int n = 0;n < 10;n++) {
		printf("%d\t", a[n]);
	}
	//���Ϊ��ѭ�����ж���Ҫ�Ƚϵ�����(�������ڳ��ȼ�1)
	for (int i = 0;i < 9;i++) {
		//�ڲ�Ϊ��ѭ����k�����ֵΪÿ����Ҫ�ȽϵĴ���(�������ڳ��ȼ������1)
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