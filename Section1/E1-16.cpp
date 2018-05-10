#include <stdio.h>

#define MAXLINE 1000        /*max input line size*/

int getline(char line[], int lim);
void copy(char to[], char from[]);

/*print longest input line*/
int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}

int getline(char line[], int lim)
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

void copy(char to[], char from[])
{
    int i = 0;
    while (to[i] = from[i])
    {
        i++;
    }
}
