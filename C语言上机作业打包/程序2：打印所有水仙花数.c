#include<stdio.h>
void main() {
	int i, ge, shi, bai;
	for(i = 100;i<999;i++){
		ge = i % 10;
		shi = (i % 100) / 10;
		bai = i / 100;
		if(i == ge*ge*ge+shi*shi*shi+bai*bai*bai){
			printf("%d\t", i);
		}
	}
}