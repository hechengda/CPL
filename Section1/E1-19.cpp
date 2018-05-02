#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int lim);
void reverse(char s[]);

/*reverse input lines, a line at a time*/
int e1_19main()
{
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
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

void reverse(char s[])
{
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0')
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
