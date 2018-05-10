#include <stdio.h>
#include <stdlib.h>     /*for atof()*/
#include <math.h>       /*for fmod()*/
#include "calc.h"

#define MAXOP   100     /*max size of operand or operator*/

/*reverse Polish calculator*/
int main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error: 0 divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(fmod(pop(), op2));
            }
            else
            {
                printf("error: 0 divisor\n");
            }
            break;
        case '?':       /*print top element of the stack*/
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':       /*clear the stack*/
            clear();
            break;
        case 'd':       /*duplicate top elem. of the stack*/
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':       /*swap the top two elem.s*/
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}
