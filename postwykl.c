#include "postwykl.h"


struct numberpolar postwykl(struct number x) {
	struct numberpolar y;
	y.absvalue = pow((x.real*x.real + x.imaginary*x.imaginary), 0.5);
	y.arg = (acos(x.real / y.absvalue)) / M_PI;
	return y;
}
