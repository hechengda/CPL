#include <math.h>

/*convert n to chars in s - w chars wide*/
void itoa(int n, char s[], int w)
{
    int i, sign;

    sign = n;       /*record sign*/
    i = 0;
    do
    {/*generate digits in reverse order*/
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    while (i < w)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);     /*do reverse op, see S3.5.cpp*/
}