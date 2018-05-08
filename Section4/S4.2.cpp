#include <ctype.h>

/*convert s to double*/
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; s[i] == ' '; i++)
    {/*skip white spaces*/
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {/*skip the sign char*/
        i++;
    }
    for (val = 0.; isdigit(s[i]); i++)
    {
        val = 10. * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {/*skip the dot char*/
        i++;
    }
    for (power = 1.; isdigit(s[i]); i++)
    {
        val = 10. * val + (s[i] - '0');
        power *= 10.;
    }
    return sign * val / power;
}