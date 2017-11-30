#include<stdio.h>
int main() {
	//����hanoi����
	void hanoi(int n, char one, char two, char three);
	int n;
	printf("please input the numbei of diskes:");
	scanf_s("%d", &n);
	printf("The step of moving %d diskes:\n ", n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
//����hanoi��������n���̴�A����B���Ƶ�C����С����ֻ�������Ϸ�
void hanoi(int n, char one, char two, char three) {
	//����move����
	void move(char x, char y);
	if (n == 1) move(one, three);
	else {
		//���õݹ�
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
		}
}
//����move�������ƶ�����
void move(char x, char y) {
	printf("%c --> %c\n", x, y);
}