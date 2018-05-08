#include <string.h>

/*reverse string s in place*/
void reverse(char s[])
{
    void rvs(char s[], int i, int len);

    rvs(s, 0, strlen(s));
}

/*reverse string s in place; recursive*/
void rvs(char s[], int i, int len)
{
    int c, j;

    j = len - (i + 1);
    if (i < j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        rvs(s, ++i, len);
    }
}
