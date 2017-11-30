#include<stdio.h>
int n , days;//定义全局变量最后那天早上剩下的桃子数n和天数days
int main() {
	int Calculate(int n);
	printf("请输入猴子吃桃的天数(到最后那天的次日早上总计天数)：\n");
	scanf_s("%d",&days);
	printf("请输入猴子第%d天早上剩下的桃子：\n",days);
	scanf_s("%d", &n);
	int sum;
	sum = Calculate(1);
	printf("猴子第一天一共摘了 %d 个桃子", sum);
	getchar();
	return 0;
}
//i为天数计时器
int Calculate(int i) {
	if (i < days)
		return 2 * (Calculate(i + 1) + 1);//每次递归至该节点，一直等待最后一个调用
	else if (i == days)//当天数计时器达到最后那天时，只剩n个桃子
		return n;
	else
		return -1;//-1表示异常
}