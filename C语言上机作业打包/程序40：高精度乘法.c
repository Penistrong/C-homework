#include<stdio.h>
#include<string.h>
int main() {
	char a[51], b[51];//俩个字符数组用以存放俩个整数
	int sum[1000] = {0}, ai[51], bi[51];//存放结果
	printf("请输入第一个整数： ");
	scanf_s("%s", a, 51);//最后一位要存放'\0'
	printf("请输入第二个整数： ");
	scanf_s("%s", b, 51);
	printf("运算中...\n");
	int i, j;
	int alen = strlen(a), blen = strlen(b);//获得有效长度(除结束字符外的所有字符数)
	for (i = 0,j=alen-1;i <= alen - 1;i++,j--) {
		ai[i] = a[j] - '0';
	}
	for (i = 0,j=blen-1;i <= blen - 1;i++,j--) {
		bi[i] = b[j] - '0';
	}//将字符数组存入整形数组中（倒序存入）
	printf("第一组长度为 %d 第二组长度为 %d\n", alen, blen);
	for (i = 0;i <= alen - 1;i++) {
		for (j = 0;j <= blen - 1;j++) {
			sum[i + j] += ai[i] * bi[j];//sum[i+j]+=会将其他的加入计算（前面循环过得到的结果）
		}/**先不处理进位*/
	}
	for (i = 0;i < alen + blen;i++) {
		if (sum[i] >= 10) {
			sum[i + 1] += sum[i] / 10;
			sum[i] %= 10;
		}
	}//处理进位
	//找到倒序乘了之后索引最高位（一定非0）的位数
	for (i = 999;i > 0;i--) {
		if (sum[i] != 0)
			break;
	}
	//倒序输出结果
	for (j = i;j >= 0;j--) {
		printf("%d", sum[j]);
	}
	return 0;
}