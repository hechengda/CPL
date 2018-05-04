#include <math.h>

/*convert n to chars in s - modified*/
void e3_4itoa(int n, char s[])
{
    int i, sign;

    sign = n;       /*record sign*/
    i = 0;
    do
    {/*generate digits in reverse order*/
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    /*do reverse op, see S3.5.cpp*/
}