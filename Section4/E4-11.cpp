#include <stdio.h>
#include <ctype.h>

#define NUMBER  '0'     /*signal that a # was found*/

/*get next operator or numeric operand*/
int getop(char s[])
{
    int i, c;
    int getch(void);
    static int lastc;

    if (lastc)
    {
        c = lastc;
        lastc = 0;
    }
    else
    {
        c = getch();
    }
    while ((s[0] = c) == ' ' || c == '\t')
    {/*skip blank space*/
        c = getch();
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {/*not number*/
        return c;
    }
    i = 0;
    if (isdigit(c))
    {/*collect integer part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.')
    {/*collect fraction part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
    {
        lastc = c;
    }
    return NUMBER;
}