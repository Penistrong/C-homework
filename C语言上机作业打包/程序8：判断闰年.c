#include<stdio.h>
void main() {
	int year;
	printf("��������ݣ�\n");
	scanf_s("%d", &year);
	if (year % 4 == 0) {
		if ((year % 100 == 0)&&(year % 400 != 0)){
			printf("���겻�����꣡");
		}
		else {
			printf("����Ϊ���꣡");
		}
	}
	else {
		printf("���겻�����꣡");
	}
}