#include<stdio.h>
#include<string.h>
int main() {
	char a[51], b[51];//�����ַ��������Դ����������
	int sum[1000] = {0}, ai[51], bi[51];//��Ž��
	printf("�������һ�������� ");
	scanf_s("%s", a, 51);//���һλҪ���'\0'
	printf("������ڶ��������� ");
	scanf_s("%s", b, 51);
	printf("������...\n");
	int i, j;
	int alen = strlen(a), blen = strlen(b);//�����Ч����(�������ַ���������ַ���)
	for (i = 0,j=alen-1;i <= alen - 1;i++,j--) {
		ai[i] = a[j] - '0';
	}
	for (i = 0,j=blen-1;i <= blen - 1;i++,j--) {
		bi[i] = b[j] - '0';
	}//���ַ�����������������У�������룩
	printf("��һ�鳤��Ϊ %d �ڶ��鳤��Ϊ %d\n", alen, blen);
	for (i = 0;i <= alen - 1;i++) {
		for (j = 0;j <= blen - 1;j++) {
			sum[i + j] += ai[i] * bi[j];//sum[i+j]+=�Ὣ�����ļ�����㣨ǰ��ѭ�����õ��Ľ����
		}/**�Ȳ������λ*/
	}
	for (i = 0;i < alen + blen;i++) {
		if (sum[i] >= 10) {
			sum[i + 1] += sum[i] / 10;
			sum[i] %= 10;
		}
	}//�����λ
	//�ҵ��������֮���������λ��һ����0����λ��
	for (i = 999;i > 0;i--) {
		if (sum[i] != 0)
			break;
	}
	//����������
	for (j = i;j >= 0;j--) {
		printf("%d", sum[j]);
	}
	return 0;
}