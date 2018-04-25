#ifndef EXTRACTNUMBER_H_INCLUDED
#define EXTRACTNUMBER_H_INCLUDED
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "structures.h"
//funkcja zczytujaca liczbe zespolona z tekstu i zwracajaca ja w formie kanonicznej
struct number extractnumber(char str[]);

#endif // EXTRACTNUMBER_H_INCLUDED
