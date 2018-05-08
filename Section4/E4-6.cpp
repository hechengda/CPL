#include <stdio.h>
#include <stdlib.h>     /*for atof()*/
#include <math.h>       /*for fmod()*/
#include <string.h>

#define MAXOP   100     /*max size of operand or operator*/
#define NUMBER  '0'     /*signal that a number was found*/
#define NAME    'n'     /*signal that a name was found*/

void matchfunc(char[]);
void push(double);
double pop(void);
void clear(void);
int getop(char[]);

/*reverse Polish calculator*/
int main()
{
    int type, i, var = 0;
    double op1, op2, v;
    char s[MAXOP];
    double variable[26];

    for (i = 0; i < 26; i++)
    {
        variable[i] = 0.0;
    }
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            matchfunc(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error: 0 divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(fmod(pop(), op2));
            }
            else
            {
                printf("error: 0 divisor\n");
            }
            break;
        case '?':       /*print top element of the stack*/
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':       /*clear the stack*/
            clear();
            break;
        case 'd':       /*duplicate top elem. of the stack*/
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':       /*swap the top two elem.s*/
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        case '=':
            pop();
            if (isupper(var))
            {
                variable[var - 'A'] = pop();
            }
            else
            {
                printf("error: no variable name\n");
            }
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
            break;
        default:
            if (isupper(type))
            {
                push(variable[type - 'A']);
            }
            else if (type == 'v')
            {
                push(v);
            }
            else
            {
                printf("error: unknown command %s\n", s);
            }
            break;
        }
        var = type;
    }

    return 0;
}

/*check string s for supported math func.s*/
void matchfunc(char s[])
{
    double op2;

    if (strcmp(s, "sin") == 0)
    {
        push(sin(pop()));
    }
    else if (strcmp(s, "cos") == 0)
    {
        push(cos(pop()));
    }
    else if (strcmp(s, "exp") == 0)
    {
        push(exp(pop()));
    }
    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
    {
        printf("error: %s not supported\n", s);
    }
}

#define MAXVAL  100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error:stack empty, can't pop\n");
        return 0.0;
    }
}

/*clear the stack*/
void clear(void)
{
    sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/*get next operator or numeric operand*/
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (islower(c))
    {/*command or NAME*/
        while (islower(s[++i] = c = getch()))
        {
            ;
        }
        s[i] = '\0';
        if (c != EOF)
        {/*went one char too far*/
            ungetch(c);
        }
        if (strlen(s) > 1)
        {/*>1 char; it's NAME*/
            return NAME;
        }
        else
        {/*it may be command*/
            return c;
        }
    }
    if (!isdigit(c) && c != '.' && c != '-')
    {/*not a number*/
        return c;
    }

    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
        {/*negative number*/
            s[++i] = c;
        }
        else
        {
            if (c != EOF)
            {
                ungetch(c);
                return '-';     /*minus sign*/
            }
        }
    }
    if (isdigit(c))
    {/*collect integer part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.')
    {/*collect fraction part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("ungetch: too many chars\n");
}
