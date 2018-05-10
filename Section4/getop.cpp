#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

/*get next operator or numeric operand*/
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        ;
    }
    s[1] = '\0';
    i = 0;
    if (islower(c))
    {/*command or NAME*/
        while (islower(s[++i] = c = getch()))
        {
            ;
        }
        s[i] = '\0';
        if (c != EOF)
        {/*went one char too far*/
            ungetch(c);
        }
        if (strlen(s) > 1)
        {/*>1 char; it's NAME*/
            return NAME;
        }
        else
        {/*it may be command*/
            return c;
        }
    }
    if (!isdigit(c) && c != '.' && c != '-')
    {/*not number*/
        return c;
    }

    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
        {/*negative number*/
            s[++i] = c;
        }
        else
        {
            if (c != EOF)
            {
                ungetch(c);
                return '-';     /*minus sign*/
            }
        }
    }
    if (isdigit(c))
    {/*collect integer part*/
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    if (c == '.')
    {/*collect fraction part*/
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}
