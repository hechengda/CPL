#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[]);

/*reverse input lines, a line at a time*/
int main()
{
    char line[MAXLINE];
    int getline(char line[], int limit);        /*see E1-16.cpp*/

    while (getline(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

void reverse(char s[])
{
    int i, j;
    char temp;

    i = 0;
    while (s[i])
    {/*find the end of string*/
        i++;
    }
    i--;        /*back off from '\0'*/
    if (s[i] == '\n')
    {
        i--;    /*leave newline in place*/
    }
    j = 0;      /* start of string*/
    while (j < i)
    {/*swap the chars*/
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j++;
        i--;
    }
}
