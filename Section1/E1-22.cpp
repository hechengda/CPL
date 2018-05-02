#include <stdio.h>

#define MAXCOL  20      /*max column of input*/
#define TABINC  8       /*tab increment size*/

char line[MAXCOL];      /*input line*/

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

/*fold long input lines into two or more shorter lines*/
int e1_22main()
{
    int c, pos = 0;
    while ((c = getchar()) != EOF)
    {
        line[pos] = c;      /*store current char*/
        if (c == '\t')
        {
            pos = exptab(pos);
        }
        else if (c == '\n')
        {
            printl(pos);
            pos = 0;
        }
        else if (++pos >= MAXCOL)
        {
            pos = findblnk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }

    return 0;
}

/*expand tab into blanks*/
int exptab(int pos)
{
    int nb = TABINC - pos % TABINC;     /*# of blanks necessary*/
    while (nb)
    {
        line[pos++] = ' ';
        nb--;
    }
    if (pos < MAXCOL)
    {/*room left in current line*/
        return pos;
    }
    else
    {/*current line is full*/
        printl(pos);
        return 0;
    }
}

/*find blank's position*/
int findblnk(int pos)
{
    do
    {
        pos--;
    } while (pos && line[pos] != ' ');
    if (!pos)
    {/*no blanks in the line*/
        return MAXCOL;
    }
    else
    {
        return pos + 1;     /*position after the blank*/
    }
}

/*rearrange line with new position*/
int newpos(int pos)
{
    if (pos <= 0 || pos >= MAXCOL)
    {
        return 0;
    }
    else
    {
        int i = 0, j = pos;
        while (j < MAXCOL)
        {
            line[i++] = line[j++];
        }
        return i;
    }
}

/*print line until pos column*/
void printl(int pos)
{
    for (int i = 0; i < pos; i++)
    {
        putchar(line[i]);
    }
    if (pos)
    {
        putchar('\n');
    }
}
