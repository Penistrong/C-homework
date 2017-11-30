#include<stdio.h>
void main() {
	int i, j;
	for (i = 1;i <= 8;i++) {
		for (j = 1;j <= 8;j++) {
			if ((i + j) % 2 == 0) {
				printf("%c%c",0xa8,0x80);
			}
			else if((i+j)%2!=0){
				printf("%c%c", 32,32);
			}
		}
		printf("\n");
	}

}