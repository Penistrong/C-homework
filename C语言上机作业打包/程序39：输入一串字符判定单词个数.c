#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int result = 0;
	char ch;
	printf("请输入一串字符并按回车键结束:\n");
	//当输入的字符不为换行符时
	while ((ch = getchar()) != '\n') {
		if (isspace(ch))
			result++;
	}
	printf("您输入的单词总数（不包括标点）为 %d 个", result + 1);
	system("pause");
	return 0;
}
