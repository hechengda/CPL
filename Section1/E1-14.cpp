#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15      /*max length of histogram*/
#define MAXCHAR 128     /*max different chars*/

/*print horizontal histogram freq. of different chars*/
int e1_14main()
{
    int c, i;
    int len;                /*length of each bar*/
    int maxvalue;           /*max value for cc[]*/
    int cc[MAXCHAR];        /*char counters*/

    for (i = 0; i < MAXCHAR; i++)
    {
        cc[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        if (c < MAXCHAR)
        {
            cc[c]++;
        }
    }
    maxvalue = 0;
    for (i = 1; i < MAXCHAR; i++)
    {
        if (cc[i] > maxvalue)
        {
            maxvalue = cc[i];
        }
    }

    for (i = 1; i < MAXCHAR; i++)
    {
        if (isprint(i))
        {
            printf("%3d - %c - %3d : ", i, i, cc[i]);
        }
        else
        {
            printf("%3d -   - %3d : ", i, cc[i]);
        }
        if (cc[i] > 0)
        {
            if ((len = cc[i] * MAXHIST / maxvalue) <= 0)
            {
                len = 1;
            }
        }
        else
        {
            len = 0;
        }
        while (len--)
        {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
