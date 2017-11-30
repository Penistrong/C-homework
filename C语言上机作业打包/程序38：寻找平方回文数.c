#include<stdio.h>
#include<math.h>
int main() {
	int i, ge, shi, bai,sum,q;
	for (i = 1;i <= 999;i++) {
		ge = i % 10;
		shi = (i % 100) / 10;
		bai = i / 100;
		sum = ge * 100 + shi * 10 + bai * 1;
		q = sqrt(i);
		if (sum == i && (q*q) == i) {
			printf("已寻找到一平方回文数： %d\n", i);
		}
	}
	return 0;
}