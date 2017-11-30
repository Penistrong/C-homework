#include<stdio.h>
#include<string.h>
void main() {
	int i = 0,count = 0;
	char s[100];
	printf("请输入英文字符串，并按回车结束：\n");
	while ((s[i] = getchar()) != '\n') {
		i++;
		count++;
	}
	for (i = 0;i <= count;i++) {
		if ((s[i] >= 'a'&&s[i] <= 'v')|(s[i] >= 'A'&&s[i] <= 'V')) {
			s[i] = s[i] + 4;

		}else{
			if ((s[i] >= 'w'&&s[i] <= 'z')|(s[i] >= 'W'&&s[i]<='Z')) {
				s[i] = s[i] - 22;
			}
			else {

			}
		}
	}
	printf("译出密码如下：\n");
	for (i = 0;i <= count;i++) {
		printf("%c", s[i]);
	}

}