#include<stdio.h>
#include<string.h>
void main() {
	unsigned long long sum = 0;
	unsigned long long m = 1;
	int i,j;
	for (i = 1;i <= 20;i++) {
		for (j = 1;j <= i;j++) {
			m = m*j;
		}
		sum = sum + m;
		m = 1;
	}
	printf("%-20llu\n", sum);
}