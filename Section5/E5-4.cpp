#include <string.h>

/*return 1 if string t occurs at the end of s*/
int strend(char *s, char *t)
{
    char *bs = s;       /*remember beginning of strs*/
    char *bt = t;

    while (*s)
    {/*end of the string*/
        s++;
    }
    while (*t)
    {
        t++;
    }
    for (; *s == *t; s--, t--)
    {
        if (t == bt || s == bs)
        {/*at the beginning of a str*/
            break;
        }
    }
    if (*s == *t && t == bt && *s != '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}