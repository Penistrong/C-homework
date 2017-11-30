#include<stdio.h>
#include<math.h>
void main() {
	double a, b, c, disc, x1, x2, p, q;
	scanf_s("%lf%lf%lf", &a, &b, &c);
	disc = b*b - 4 * a * c;
	if (disc < 0) {
		printf("这个方程没有根\n");
	}
	else {
		p = - b / (2.0*a);
		q = sqrt(disc) / (2.0*a);
		x1 = p + q;
		x2 = p - q;
		printf("x1=%7.2f\tx2=%7.2f\n", x1, x2);
	}
}