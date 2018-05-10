#include <stdio.h>

void remove_comment(int c);
void in_comment(void);
void echo_quote(int c);

/*remove all comments from a valid C program*/
int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        remove_comment(c);
    }

    return 0;
}

/*read each char, remove the comments*/
void remove_comment(int c)
{
    int d;

    if (c == '/')
    {
        if ((d = getchar()) == '*')
        {/* start of comment*/
            in_comment();
        }
        else if (d == '/')
        {/*another slash*/
            putchar(c);
            remove_comment(d);
        }
        else
        {/*not a comment*/
            putchar(c);
            putchar(d);
        }
    }
    else if (c == '\'' || c == '"')
    {/*quote begins*/
        echo_quote(c);
    }
    else
    {/*not a comment*/
        putchar(c);
    }
}

/*inside of a valid comment*/
void in_comment(void)
{
    int c, d;

    c = getchar();      /*prev char*/
    d = getchar();      /*current char*/
    while (c != '*' || d != '/')
    {/*search for end*/
        c = d;
        d = getchar();
    }
}

/*echo chars within quotes*/
void echo_quote(int c)
{
    int d;

    putchar(c);
    while ((d = getchar()) != c)
    {/*search for end*/
        putchar(d);
        if (d == '\\')
        {/*ignore escape seq*/
            putchar(getchar());
        }
    }
    putchar(d);
}
