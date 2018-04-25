#include "power.h"

struct number power(struct number x, double p) {
	struct number y;
	double real1, real2, real;
	real1 = x.real;
	real2 = x.real;
	real = x.real;
	double imaginary1, imaginary2, imaginary;
	imaginary1 = x.imaginary;
	imaginary2 = x.imaginary;
	imaginary = x.imaginary;
	int i;
	for (i = 1; i < p; i++) {
		real1 = real * x.real;
		imaginary1 = imaginary * x.real;
		imaginary2 = real * x.imaginary;
		real2 = imaginary * x.imaginary * (-1);
		//printf("real = %lf + %lf\n", real1, real2);
		real = real1 + real2;
		//printf("imaginary = %lf + %lf\n", imaginary1, imaginary2);
		imaginary = imaginary1 + imaginary2;
		//printf("interacja: %d, r = %lf, i = %lf\n", i, real1, imaginary1);
	}
	y.real = real;
	y.imaginary = imaginary;
	return y;
}
