#define NUMBER  '0'
#define NAME    'n'     /*signal that a name was found*/

void push(double);
double pop(void);
void clear(void);
int getop(char[]);
int getch(void);
void ungetch(int);
void matchfunc(char s[]);