#include <math.h>

/*convert n to chars in s - base b*/
void itob(int n, char s[], int b)
{
    int i, j, sign;

    sign = n;       /*record sign*/
    i = 0;
    do
    {/*generate digits in reverse order*/
        j = abs(n % b);
        s[i++] = (j <= 9) ? (j + '0') : (j + 'a' - 10);
    } while ((n /= b) != 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    /*do reverse op, see S3.5.cpp*/
}