#include <stdio.h>

#define TABINC  4

/*replace strings of blanks with tabs and blanks*/
int main()
{
    int c, nb, nt, pos;

    nb = 0;         /*# of blanks necessary*/
    nt = 0;         /*# of tabs necessary*/
    pos = 0;        /*position of cursor in line*/
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
            while (nt-- > 0)
            {/*output tab(s)*/
                putchar('\t');
            }
            if (c == '\t')
            {/*forget the blank(s)*/
                nb = 0;
            }
            else
            {/*output blank(s)*/
                while (nb-- > 0)
                {
                    putchar(' ');
                }
            }
            putchar(c);
            if (c == '\n')
            {/*newline char*/
                pos = 0;        /*reset position*/
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
