#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calc.h"

/*check string s for supported math func.s*/
void matchfunc(char s[])
{
    double op2;

    if (!strcmp(s, "sin"))
    {
        push(sin(pop()));
    }
    else if (!strcmp(s, "cos"))
    {
        push(cos(pop()));
    }
    else if (!strcmp(s, "exp"))
    {
        push(exp(pop()));
    }
    else if (!strcmp(s, "pow"))
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
    {
        printf("error: %s not supported\n", s);
    }
}
