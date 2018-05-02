#include <stdio.h>

#define MAXLINE     1000
#define LONGLINE    80

int e1_17getline(char line[], int lim);

/*print lines longer than LONGLINE*/
int e1_17main()
{
    int len;
    char line[MAXLINE];

    while ((len = e1_17getline(line, MAXLINE)) > 0)
    {
        if (len > LONGLINE)
        {
            printf("%s", line);
        }
    }

    return 0;
}

int e1_17getline(char line[], int lim)
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
