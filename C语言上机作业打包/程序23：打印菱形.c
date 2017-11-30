#include<stdio.h>
int main() {
	int i, j;
	for (i = 1;i <= 15;i++) {
		if (i <= 8) {
			for (j = 1;j <= i;j++) {
				printf("*");
			}
		}
		else{
			for (j = 8-(i-8);j >= 1;j--) {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}