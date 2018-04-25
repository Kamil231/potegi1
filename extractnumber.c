#include "extractnumber.h"

#define M_PI 3.14159265358979323846

struct number extractnumber(char str[]) {
	char *end;
	struct number x;
	double a, b;
	a = strtod(str, &end);
	if ((*end == '+' || *end == '-') && *(end + 1) == 'j') {
		b = strtod(end + 2, NULL);
		if (*end == '-')
			b = b* (-1);
		if (*str == '-')
			a = a *(-1);
		x.real = a;
		x.imaginary = b;
	}
	else if (*end == 'e' && *(end + 1) == 'x' && *(end + 2) == 'p' && *(end + 3) == '(' && (*(end + 4) == 'j' || (*(end + 5) == 'j' && *(end + 4) == '-'))) {
		if (*(end + 4) == 'j')
			b = strtod(end + 5, NULL);
		else {
			b = strtod(end + 6, NULL);
			b = b*(-1);
		}
		x.real = a * cos(b*M_PI);
		x.imaginary = a * sin(b*M_PI);
	}
	else if (*end == NULL && (isdigit(*str)||*str=='-')) {
		if (*str == 'j')
			a = a * (-1);
		x.real = a;
		x.imaginary = 0;
	}
	else if (*str == 'j' || (*str == '-' && *(str+1)=='j')) {
		a = strtod(str + 1, &end);
		if (*str == '-') {
			a = strtod(str + 2, &end);
			a = a*(-1);
		}
		x.real = 0;
		x.imaginary = a;
	}

	return x;

}
