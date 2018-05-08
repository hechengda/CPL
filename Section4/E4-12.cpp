/*convert n to chars in s; recursive*/
void itoa(int n, char s[])
{
    static int i;

    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
    {
        itoa(n / 10, s);
    }
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}

#include <math.h>

void itob(int n, char s[])
{
    static int i;

    if (n / 10)
    {
        itoa(n / 10, s);
    }
    else
    {
        i = 0;
        if (n < 0)
        {
            s[i++] = '-';
        }
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}
