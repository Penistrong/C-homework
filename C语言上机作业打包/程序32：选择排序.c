#include<stdio.h>
#include<string.h>
int main() {
	int num[] = { 12,65,94,32,76,48 };
	//ʹ��sizeof������鳤��
	int length = sizeof(num)/sizeof(num[0]);
	void SelectionSort(num, length);
	SelectionSort(num, length);
	for (int i = 0;i < length;i++) {
		printf("%d ", num[i]);
	}
	return 0;
}
void SelectionSort(int *num, int length) {
	int i = 0, min = 0, j = 0, temp = 0;
	for (i = 0;i < length;i++) {
		min = i;//��ÿ����С�±���Ϊi
		//������δ���е�ʣ�������ҵ���С�������±�
		for (j = i;j < length;j++) {
			if (num[min] > num[j]) min = j;
		}
		//�����С����������ʼλ�õ�Ԫ�أ�������ʼԪ�ؽ���λ��
		if (min != i) {
			temp = num[min];
			num[min] = num[i];
			num[i] = temp;
		}
	}
}