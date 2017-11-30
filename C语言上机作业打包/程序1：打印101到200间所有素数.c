#include<stdio.h>
#include<math.h>
void main() {
	int i = 101;
	int j = 2;
	int N = 0;
	int w = 0;
	for (i;i <= 200;++i) {
		for (j=2;j <= sqrt(i);++j) {
			if (i%j == 0) {
				w = 1;
				break;
			}
			else {
				w = 0;
			}
			
		}
		if (w == 0) {
			printf("%d\t", i);
			N = N + 1;
		}

	}
	printf("\n共有%d个素数\n", N);
		
}

