#include <string.h>

/*delete white spaces, tabs and newlines at the end of string s*/
int trim(char s[])
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
    {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        {
            break;
        }
    }
    s[n + 1] = '\0';
    return n;
}