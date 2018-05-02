#include <stdio.h>

#define TABINC  8       /*tab increment size*/

/*replace tabs with the proper # of blanks*/
int e1_20main()
{
    int c, nb, pos;

    nb = 0;         /*# of blanks necessary*/
    pos = 0;        /* position of cursor in line*/
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {/*tab char*/
            nb = TABINC - pos % TABINC;
            while (nb)
            {
                putchar(' ');
                pos++;
                nb--;
            }
        }
        else if (c == '\n')
        {/*newline char*/
            putchar(c);
            pos = 0;
        }
        else
        {/*other chars*/
            putchar(c);
            pos++;
        }
    }

    return 0;
}
