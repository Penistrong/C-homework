#include<stdio.h>
int main() {
	unsigned long long sum;
	int n;
	printf("���������֣�\n");
	scanf_s("%d", &n);
	unsigned long long Result(int n);
	sum = Result(n);
	printf("%I64u\n", sum);
	return 0;
}
//����һ������ÿ�����ֵĽ׳˵ĵݹ麯��
unsigned long long Calculate(int n) {
	if (n == 1) return 1;
	//�ݹ����ʱ���ص�ֵ�ɿ����ϴο�ʼ����ʱ��ĳ�α������ı��ʽ
	return n*Calculate(n - 1);
}
//����һ������׳˺͵ĵݹ麯�����Ҹú��������еݹ�������ϸ��ݹ麯��Calculate
unsigned long long Result(int n) {
	if (n == 1) return 1;
	return Calculate(n) + Result(n - 1);
}