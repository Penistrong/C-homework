#include<stdio.h>
#include<string.h>
int main() {
	int num[] = { 12,65,94,32,76,48 };
	//使用sizeof获得数组长度
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
		min = i;//将每次最小下标设为i
		//遍历尚未排列的剩余数，找到最小的数的下标
		for (j = i;j < length;j++) {
			if (num[min] > num[j]) min = j;
		}
		//如果最小的数并非起始位置的元素，就与起始元素交换位置
		if (min != i) {
			temp = num[min];
			num[min] = num[i];
			num[i] = temp;
		}
	}
}