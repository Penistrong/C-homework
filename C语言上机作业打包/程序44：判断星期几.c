#include<stdio.h>
int main() {
	char str[10];
	printf("�������������ڼ���Ӣ��,����ĸ���д��\n");
	gets(str);
	switch (str[0]) {
	case 'M':
		printf("����������һ��");
		break;
	case 'T':
		if (str[1] == 'u')
			printf("���������ڶ���");
		else printf("�����������ģ�");
		break;
	case 'W':
		printf("��������������");
		break;
	case 'F':
		printf("�����������壡");
		break;
	case 'S':
		if (str[1] == 'a')
			printf("��������������");
		else if (str[1] == 'u')
			printf("������������");
		break;
	default:
		printf("�������˷Ƿ��ַ����޷��ж�");
	}
	return 0;
}