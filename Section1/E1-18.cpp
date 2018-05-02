#include <stdio.h>

#define MAXLINE 1000

int e1_18getline(char line[], int lim);
int remove(char s[]);

/*remove trailing blanks and tabs, and delete blank lines*/
int e1_18main()
{
    char line[MAXLINE];

    while (e1_18getline(line, MAXLINE) > 0)
    {
        if (remove(line) > 0)
        {
            printf("%s", line);
        }
    }

    return 0;
}

int e1_18getline(char line[], int lim)
{
    int c, i, j;

    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i < lim - 2)
        {
            line[j++] = c;
        }
    }
    if (c == '\n')
    {
        line[j++] = c;
        i++;
    }
    line[j] = '\0';

    return i;
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
