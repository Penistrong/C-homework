#include<stdio.h>
int main() {
	unsigned long long sum;
	int n;
	printf("请输入数字：\n");
	scanf_s("%d", &n);
	unsigned long long Result(int n);
	sum = Result(n);
	printf("%I64u\n", sum);
	return 0;
}
//创建一个计算每个数字的阶乘的递归函数
unsigned long long Calculate(int n) {
	if (n == 1) return 1;
	//递归调用时返回的值可看做上次开始调用时的某次本身函数的表达式
	return n*Calculate(n - 1);
}
//创建一个计算阶乘和的递归函数，且该函数在其中递归调用了上个递归函数Calculate
unsigned long long Result(int n) {
	if (n == 1) return 1;
	return Calculate(n) + Result(n - 1);
}