#include <ctype.h>
#include <string.h>

/*convert s to int; 2nd version*/
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
    {/*ignore white spaces*/
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {/*ignore the sign char*/
        i++;
    }
    for (n = 0; isdigit(s[i]); i++)
    {
        n = n * 10 + (s[i] - '0');
    }
    return sign * n;
}

/*sort v[0]...v[n-1] in ascending order*/
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

/*reverse the chars in the string s*/
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
