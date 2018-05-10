#include <stdio.h>

#define MAXLINE     1000
#define LONGLINE    80

/*print lines longer than LONGLINE*/
int main()
{
    int len;
    char line[MAXLINE];
    int getline(char line[], int limit);        /*see E1-16.cpp*/

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > LONGLINE)
        {
            printf("%s", line);
        }
    }

    return 0;
}
