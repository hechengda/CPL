#include <stdio.h>

/*read a line into s, return length*/
int getline(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *s++ = c;
    }
    if (c == '\n')
    {
        *s++ = c;
    }
    *s = '\0';
    return s - t;
}

#include <ctype.h>
/*convert s to integer; pointer version*/
int atoi(char *s)
{
    int n, sign;

    while (isspace(*s))
    {
        s++;
    }
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
    {
        s++;
    }
    for (n = 0; isdigit(*s); s++)
    {
        n = 10 * n + s - '0';
    }
    return sign * n;
}

void reverse(char *);

/*convert n to chars in s; pointer version*/
void itoa(int n, char *s)
{
    int sign;
    char *t = s;

    if ((sign = n) < 0)
    {
        n = -n;
    }
    do
    {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
    {
        *s++ = '-';
    }
    *s = '\0';
    reverse(t);
}

/*reverse string s in place*/
void reverse(char *s)
{
    int c;
    char *t;

    for (t = s + (strlen(s) - 1); s < t; s++, t--)
    {
        c = *s;
        *s = *t;
        *t = c;
    }
}

/*return index of t in s, -1 if none*/
int strindex(char *s, char *t)
{
    char *b = s;
    char *p, *r;

    for (; *s != '\0'; s++)
    {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
        {
            ;
        }
        if (r > t && *r == '\0')
            return s - b;
    }
    return -1;
}

/*convert string s to double; pointer version*/
double atof(char *s)
{
    double val, power;
    int sign;

    while (isspace(*s))
    {
        s++;
    }
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
    {
        s++;
    }
    for (val = 0.0; isdigit(*s); s++)
    {
        val = 10.0 * val + (*s - '0');
    }
    if (*s == '.')
    {
        s++;
    }
    for (power = 1.0; isdigit(*s); s++)
    {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    return sign * val / power;
}