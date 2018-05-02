#include <stdio.h>

#define TABINC  8

/*replace strings of blanks with tabs and blanks*/
int e1_21main()
{
    int c, nb, nt, pos;

    nb = 0;         /*# of blanks necessary*/
    nt = 0;         /*# of tabs necessary*/
    pos = 0;        /* position of cursor in line*/
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (++pos % TABINC)
            {
                nb++;       /*increment # of blanks*/
            }
            else
            {
                nb = 0;     /*reset # of blanks*/
                nt++;       /*one more tab*/
            }
        }
        else
        {
            while (nt)
            {/*output tab(s)*/
                putchar('\t');
                nt--;
            }
            if (c == '\t')
            {/*forget the blank(s)*/
                nb = 0;
            }
            else
            {/*output blank(s)*/
                while (nb)
                {
                    putchar(' ');
                    nb--;
                }
            }
            putchar(c);
            if (c == '\n')
            {/*newline char*/
                pos = 0;
            }
            else if (c == '\t')
            {/*tab char*/
                pos += (TABINC - pos % TABINC);
            }
            else
            {/*other chars*/
                pos++;
            }
        }
    }

    return 0;
}
