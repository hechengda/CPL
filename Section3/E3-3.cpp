/*expand shorthand notation in s1 into string s2*/
void expand(char s1[], char s2[])
{
    char c;
    int i, j;

    i = j = 0;
    while (c = s1[i++])
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
