#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int result = 0;
	char ch;
	printf("������һ���ַ������س�������:\n");
	//��������ַ���Ϊ���з�ʱ
	while ((ch = getchar()) != '\n') {
		if (isspace(ch))
			result++;
	}
	printf("������ĵ�����������������㣩Ϊ %d ��", result + 1);
	system("pause");
	return 0;
}
