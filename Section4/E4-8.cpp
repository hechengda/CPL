#include <stdio.h>

static char buf = 0;

/*get a (possibly pushed back) char*/
int getch(void)
{
    int c;

    if (buf)
    {
        c = buf;
        buf = 0;
    }
    else
    {
        c = getchar();
    }
    return c;
}

/*push char back onto the input*/
void ungetch(int c)
{
    if (buf)
    {
        printf("ungetch: too many chars\n");
    }
    else
    {
        buf = c;
    }
}
