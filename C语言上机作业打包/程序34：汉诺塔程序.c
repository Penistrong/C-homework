#include<stdio.h>
int main() {
	//声明hanoi函数
	void hanoi(int n, char one, char two, char three);
	int n;
	printf("please input the numbei of diskes:");
	scanf_s("%d", &n);
	printf("The step of moving %d diskes:\n ", n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
//定义hanoi函数，将n个盘从A棒经B棒移到C棒，小盘子只能在最上方
void hanoi(int n, char one, char two, char three) {
	//声明move函数
	void move(char x, char y);
	if (n == 1) move(one, three);
	else {
		//利用递归
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
		}
}
//定义move函数，移动盘子
void move(char x, char y) {
	printf("%c --> %c\n", x, y);
}