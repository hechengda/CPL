#include <stdio.h>

#define IN  1
#define OUT 0

/*print input one word per line*/
int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
            {/*end of word*/
                state = OUT;
                putchar('\n');
            }
        }
        else if (state == OUT)
        {/*start of word*/
            state = IN;
            putchar(c);
        }
        else
        {/*inside a word*/
            putchar(c);
        }
    }

    return 0;
}
