#include <stdio.h>

#define MAXLINE 1000

int s1_9getline(char line[], int lim);
void s1_9copy(char to[], char from[]);

int s1_9main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while ((len = s1_9getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            s1_9copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}

int s1_9getline(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i++] = c;
    }
    line[i] = '\0';

    return i;
}

void s1_9copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}
