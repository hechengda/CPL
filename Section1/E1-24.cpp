#include <stdio.h>

int brace, brack, paren;

void in_quote(int c);
void search(int c);

/*rudimentary syntax checher for C programs*/
int main()
{
    int c;
    void in_comment(void);      /*see E1-23.cpp*/

    while ((c = getchar()) != EOF)
    {
        if (c == '/')
        {
            if ((c = getchar()) == '*')
            {/*inside comment*/
                in_comment();
            }
            else
            {
                search(c);
            }
        }
        else if (c == '\'' || c == '"')
        {/*inside quote*/
            in_quote(c);
        }
        else
        {
            search(c);
        }

        if (brace < 0)
        {
            printf("Unbalanced braces\n");
            brace = 0;
        }
        else if (brack < 0)
        {
            printf("Unbalanced bracks\n");
            brack = 0;
        }
        else if (paren < 0)
        {
            printf("Unbalanced parentheses\n");
            paren = 0;
        }
    }

    if (brace > 0)
    {
        printf("Unbalanced braces\n");
    }
    if (brack > 0)
    {
        printf("Unbalanced bracks\n");
    }
    if (paren > 0)
    {
        printf("Unbalanced parentheses\n");
    }

    return 0;
}

/*inside quote*/
void in_quote(int c)
{
    int d;

    while ((d = getchar()) != c)
    {/*search end quote*/
        if (d == '\\')
        {/*ignore escape seq*/
            getchar();
        }
    }
}

/*search for rudimentary syntax errors*/
void search(int c)
{
    if (c == '{')
    {
        brace++;
    }
    else if (c == '}')
    {
        brace--;
    }
    else if (c == '[')
    {
        brack++;
    }
    else if (c == ']')
    {
        brack--;
    }
    else if (c == '(')
    {
        paren++;
    }
    else if (c == ')')
    {
        paren--;
    }
}
