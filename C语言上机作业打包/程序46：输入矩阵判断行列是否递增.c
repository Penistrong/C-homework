#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[3][3];//����һ��3X3��ά����
	int i, j, h;
	void Check(int b[][3]);//�����������Ƿ�����ĺ���
	for (i = 0;i <= 2;i++) {
		h = i + 1;
		printf("�������%d�е�1����:\n",h);
		for (j=0;j <= 2;j++) {
			scanf_s("%d", &a[i][j]);
			if (j < 2)
				printf("��������һ����:\n");
		}
	}
	//��ӡ����
	printf("������ľ�������:\n");
	for (i = 0;i <= 2;i++) {
		for (j = 0;j <= 2;j++) {
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
	Check(a[3][3]);
	system("pause");
	return 0;
}
void Check(int b[][3]) {
	int i, h, l;//h,l�ֱ��ʾ�У���
	//�ж�ÿ���Ƿ����
	for (i = 0;i <= 2;i++) {
		h = i + 1;
		if (b[i][0] < b[i][1] && b[i][1] < b[i][2])
			printf("��%d���ǵ�����\n", h);
		else
			printf("��%d�в�����\n", h);
	}
	//�ж�ÿ���Ƿ����
	for (i = 0;i <= 2;i++) {
		l = i + 1;
		if (b[0][i] < b[1][i] && b[1][i] < b[2][i])
			printf("��%d���ǵ�����\n", l);
		else
			printf("��%d�в�����\n", l);
	}
}