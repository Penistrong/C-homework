#include<stdio.h>
#include<string.h>
int main() {
	char a[50], b[50];
	//��������c�����Դ�Ž��
	int sum[100] = { 0 }, ia[50] = { 0 }, ib[50] = { 0 };
	printf("�������һ������\n");
	scanf_s("%s", a, 50);
	printf("������ڶ�������\n");
	scanf_s("%s", b, 50);
	int alen = strlen(a), blen = strlen(b);//�õ��������ĳ���
	printf("��һ����������Ϊ %d\n�ڶ�����������Ϊ %d\n",alen,blen);
	//���õ��������ַ��������������Լ��������������
	int i, j, maxlen;
	for (i = 0, j = alen - 1;i <= alen - 1;i++, j--) {
		ia[i] = a[j] - '0';
	}
	for (i = 0, j = blen - 1;i <= blen - 1;i++, j--) {
		ib[i] = b[j] - '0';
	}
	//�ȼ��㣬�ٴ����λ
	for (i = 0;i <= alen - 1;i++) {
		sum[i] = ia[i] + ib[i];
	}
	if (alen < blen) {
		maxlen = blen;
		for (j = alen;j <= blen - 1;j++) {
			sum[j] = ib[j];
		}
	}
	else if(alen > blen){
		maxlen = alen;
		for (j = blen;j <= alen - 1;j++) {
			sum[j] = ia[j];
		}
	}//�����������Ȳ�ͬ������
	for (i = 0;i <= maxlen - 1;i++) {
		if (sum[i] >= 10) {
			sum[i+1] += sum[i] / 10;
			sum[i] %= 10;
		}
	}
	for (i = 99;i >= 0;i--) {
		if (sum[i] != 0)
			break;
	}
	for (j = i;j >= 0;j--) {
		printf("%d", sum[j]);
	}
	return 0;
}

