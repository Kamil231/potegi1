#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <ctype.h>
#include "structures.h"
#include "power.h"
#include "postwykl.h"
#include "extractnumber.h"
#define M_PI 3.14159265358979323846
//struktura liczby zespolonej zawierajaca czesc rzeczywista i urojona w postaci  kanonicznej
/*struct number {
	double imaginary;
	double real;		//0 if real, 1 if imaginary
};
//struktura liczby zespolonej w postaci wykladniczej
struct numberpolar {
	double absvalue;
	double arg;
};*/

//funkcja przyjmujaca liczbe zepolona w postaci kanonicznej i potegujaca do potegi p, zwraca liczbe zepolona w postaci kanonicznej
/*struct number power(struct number x, double p) {
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
}*/
//funkcja przyjmujaca liczbe zespolona w postaci kanonicznej i zwracajaca postac wykladnicza
/*struct numberpolar postwykl(struct number x) {
	struct numberpolar y;
	y.absvalue = pow((x.real*x.real + x.imaginary*x.imaginary), 0.5);
	y.arg = (acos(x.real / y.absvalue)) / M_PI;
	return y;
}*/

//funkcja zczytujaca liczbe zespolona z tekstu i zwracajaca ja w formie kanonicznej
/*struct number extractnumber(char str[]) {
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

}*/




//funkcja sprawdzajaca czy wpisany tekst jest prawidlowy
int checkinput(char str[]) {
	int q = 0;
	char *end, *end1;
	int k = 0;
	double a, b, z = 1;
	if (!isdigit(*str) && *str != '-' && *str != 'j') {
		printf("Blad! ->          ");
		printf("^\n");
		if (*str == '-')
			z = -1;
	}
	a = strtod(str, &end);
	if (*str == 'j')
		a = strtod(str + 1, &end);
	a = a*z;
	if (*end == NULL && isdigit(*str)||(*str == '-' && isdigit(*(str+1)))) {
		if (*str == '-') {
			a = strtod(str + 1, &end);
			a = a*(-1);
		}
		return 0;
	}
	if (*str == 'j' && *end == NULL) {
		return 0;
	}
	int i = 0;
	while (end != str) {
		i++;
		str++;
	}
	if (*end != '+' && *end != '-' && *(end + 4) == '-') {
		str = end + 6;
		b = strtod(str, &end1);
		while (end1 != str) {
			k++;
			str++;
		}
	}
	else if (*end != '+' && *end != '-' && *(end + 4) != '-') {
		str = end + 5;
		b = strtod(str, &end1);
		while (end1 != str) {
			k++;
			str++;
		}
	}

	if (*end != '+' && *end != '-' && *end != 'e') {
		printf("Blad! ->          ");
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("^\n");
		q = 1;
	}
	else if (*(end + 1) != 'j' && *(end + 1) != 'x') {
		printf("Blad! ->          ");
		for (int j = 0; j < i; j++)
			printf(" ");
		printf(" ^\n");
		q = 1;
	}

	else if (*(end + 2) != 'p' && *(end + 1) != 'j') {
		printf("Blad! ->          ");
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("  ^\n");
		q = 1;
	}
	else if (*(end + 3) != '(' && *(end + 1) != 'j') {
		printf("Blad! ->          ");
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("   ^\n");
		q = 1;
	}
	else if (*(end + 4) != '-'&&*(end + 4) != 'j' && *(end + 1) != 'j') {
		printf("Blad! ->          ");
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("    ^\n");
		q = 1;
	}
	else if (*(end + 4) == '-'&&*(end + 5) != 'j') {
		printf("Blad! ->          ");
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("     ^\n");
		q = 1;
	}


	//
	else if ((*(end + 1) != 'j' || *(end + 4) == '-')) {
		if (*(end1) != 'p') {
			printf("Blad! ->          ");
			for (int j = 0; j < i + k; j++)
				printf(" ");
			printf("     ^\n");
			q = 1;
		}
	}
	else if ((*(end + 1) != 'j' || *(end + 4) == '-')) {
		if (*(end1 + 1) != 'i') {
			printf("Blad! ->          ");
			for (int j = 0; j < i + k; j++)
				printf(" ");
			printf("       ^\n");
			q = 1;
		}
	}
	else if ((*(end + 1) != 'j' || *(end + 4) == '-')) {
		if (*(end1) != 'p') {
			printf("Blad! ->          ");
			for (int j = 0; j < i + k; j++)
				printf(" ");
			printf("       ^\n");
			q = 1;
		}
	}
	return q;
}



void main() {

	struct number x, y;
	int p, q = 0;
	char tekst[100];
	int i;
	for (i = 0; i < 100; ++i) {
		tekst[i] = NULL;
	}
	printf("Liczba zespolona: ");
	scanf("%s", &tekst);
	q = checkinput(tekst);
	if (q == 1)
		return;
	printf("Stopien potegi: ");
	scanf("%d", &p);
	x = extractnumber(tekst);
	y = power(x, p);
	printf("Wynik (postac kanoniczna) : %lf+j%lf\n", y.real, y.imaginary);
	struct numberpolar z;
	z = postwykl(y);
	printf("Wynik (postac wykladnicza) : %lfexp(j%lfpi)", z.absvalue, z.arg);
}
