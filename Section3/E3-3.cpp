#include <stdio.h>

void expand(char[], char[]);

int main()
{
    char s1[] = "a-z";
    char s2[128];
    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}

/*expand shorthand notation in s1 into string s2*/
void expand(char s1[], char s2[])
{
    char c;
    int i, j;

    i = j = 0;
    while ((c = s1[i++]) != '\0')
    {/*fetch a char from s1*/
        if (s1[i] == '-' && s1[i + 1] >= c)
        {
            i++;
            while (c < s1[i])
            {/*expand shorthand*/
                s2[j++] = c++;
            }
        }
        else
        {/*copy the char*/
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}
