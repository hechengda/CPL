#include <stdio.h>
#include <ctype.h>

/*get next floating-point # from input*/
int getfloat(float *pn)
{
    int c, sign;
    float power;
    int getch(void);
    void ungetch(int);

    while (isspace(c = getch()))
    {/*skip white space*/
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {/*not a #*/
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }
    for (*pn = 0.f; isdigit(c); c = getch())
    {/*integer part*/
        *pn = 10.f * *pn + (c - '0');
    }
    if (c == '.')
    {
        c = getch();
    }
    for (power = 1.f; isdigit(c); c = getch())
    {/*fractional part*/
        *pn = 10.f * *pn + (c - '0');
        power *= 10.f;
    }
    *pn *= sign / power;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}
