#include <stdio.h>

#define MAXLINE 1000

int remove(char s[]);

/*remove trailing blanks and tabs, and delete blank lines*/
int main()
{
    char line[MAXLINE];
    int getline(char line[], int limit);        /*see E1-16.cpp*/

    while (getline(line, MAXLINE) > 0)
    {
        if (remove(line) > 0)
        {
            printf("%s", line);
        }
    }

    return 0;
}

int remove(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\n')
    {/*find newline char*/
        i++;
    }
    i--;    /*back off from newline char*/
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
    {
        i--;
    }
    if (i >= 0)
    {
        s[++i] = '\n';
        s[++i] = '\0';
    }

    return i;
}
