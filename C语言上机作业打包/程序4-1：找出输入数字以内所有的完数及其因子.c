#include<stdio.h>
void main() {
	int p[80];
	int n, i, count, temp, sum = 0;
	int Maxnum;
	printf("����������ҪѰ�ҵķ�Χ���ޣ�");
	scanf_s("%d",&Maxnum);
	for (n = 2;n < Maxnum;n++) {
		count = 0;
		temp = n;
		for (i = 1;i <= n - 1;i++) {
			if (n%i == 0) {
				//��������������������������������ӱ��������,
				p[count++] = i;
				//����������ӣ�ѭ��ֱ��temp����0���⼴�������ӵĺ͵���ԭ��
				temp -= i;
			}
		}
		if (temp == 0) {
			printf("%4d��һ�������������У�", n);
			printf("%d = %d", n, p[0]);
			for (i = 1;i < count;i++) {
				printf("+ %d", p[i]);
			}
			printf("\n");
			sum++;
		}
	}	
	printf("����%d������\n", sum);
}