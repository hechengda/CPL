#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define NUMBER  '0'     /*signal that a # was found*/

static int li = 0;     /*input line index*/
static char line[MAXLINE];     /*one input line*/

int getop(char s[])
{
    int i, c;
    int getline(char line[], int limit);

    if (line[li] == '\0')
    {
        if (getline(line, MAXLINE))
        {
            li = 0;
        }
        else
        {
            return EOF;
        }
    }
    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {/*not number*/
        return c;
    }
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;
    return NUMBER;
}
