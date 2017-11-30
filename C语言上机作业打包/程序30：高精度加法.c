#include<stdio.h>
#include<string.h>
int main() {
	char a[50], b[50];
	//创建数组c，用以存放结果
	int sum[100] = { 0 }, ia[50] = { 0 }, ib[50] = { 0 };
	printf("请输入第一个数：\n");
	scanf_s("%s", a, 50);
	printf("请输入第二个数：\n");
	scanf_s("%s", b, 50);
	int alen = strlen(a), blen = strlen(b);//得到俩串数的长度
	printf("第一个整数长度为 %d\n第二个整数长度为 %d\n",alen,blen);
	//将得到的整数字符串倒序填入用以计算的整型数组中
	int i, j, maxlen;
	for (i = 0, j = alen - 1;i <= alen - 1;i++, j--) {
		ia[i] = a[j] - '0';
	}
	for (i = 0, j = blen - 1;i <= blen - 1;i++, j--) {
		ib[i] = b[j] - '0';
	}
	//先计算，再处理进位
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
	}//处理俩个长度不同的整数
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

