#include<stdio.h>
int main() {
	char str[10];
	printf("请正常输入星期几的英文,首字母需大写：\n");
	gets(str);
	switch (str[0]) {
	case 'M':
		printf("这天是星期一！");
		break;
	case 'T':
		if (str[1] == 'u')
			printf("这天是星期二！");
		else printf("这天是星期四！");
		break;
	case 'W':
		printf("这天是星期三！");
		break;
	case 'F':
		printf("这天是星期五！");
		break;
	case 'S':
		if (str[1] == 'a')
			printf("这天是星期六！");
		else if (str[1] == 'u')
			printf("这天是星期天");
		break;
	default:
		printf("您输入了非法字符！无法判断");
	}
	return 0;
}