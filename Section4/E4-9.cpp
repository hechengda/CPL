#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];       /*buffer for ungetch*/
int bufp = 0;           /*next free pos in buf*/

/*get a (possibly pushed back) char*/
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/*push char back onto the input*/
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many chars\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
