#include <ctype.h>

/*convert hex string s to int*/
int htoi(char s[])
{
    int i, n, hexdigit;

    i = 0;
    if (s[i++] == '0')
    {/*skip optional 0x or 0X*/
        if (s[i] == 'x' || s[i] == 'X')
        {
            i++;
        }
    }

    for (n = 0; isxdigit(s[i]); i++)
    {
        if (isdigit(s[i]))
        {
            hexdigit = s[i] - '0';
        }
        else
        {
            hexdigit = tolower(s[i]) - 'a';
        }
        n = 16 * n + hexdigit;
    }

    return n;
}
