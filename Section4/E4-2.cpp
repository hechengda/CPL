#include <ctype.h>

/*convert string s to double*/
double atof(char s[])
{
    double val, power;
    int i, sign, exp;

    for (i = 0; s[i] == ' '; i++)
    {/*skip white space*/
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {/*skip sign char*/
        i++;
    }
    for (val = 0.; isdigit(s[i]); i++)
    {
        val = 10. * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {/*skip dot char*/
        i++;
    }
    for (power = 1.; isdigit(s[i]); i++)
    {
        val = 10. * val + (s[i] - '0');
        power *= 10.;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E')
    {
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
        {/*skip the sign char*/
            i++;
        }
        for (exp = 0; isdigit(s[i]); i++)
        {
            exp = 10 * exp + (s[i] - '0');
        }
        if (sign == 1)
            while (exp-- > 0)
            {
                val *= 10;
            }
        else
            while (exp-- > 0)
            {
                val /= 10;
            }
    }
    return val;
}
