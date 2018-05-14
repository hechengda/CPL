/*copy n chars from t to s*/
void strncpy(char *s, char *t, int n)
{
    while (n-- && (*s++ = *t++))
    {
        ;
    }
}

/*concatenate n chars of t to the end of s*/
void strncat(char *s, char *t, int n)
{
    void strncpy(char *, char *, int);
    int strlen(char *);

    strncpy(s + strlen(s), t, n);
}

/*compare at most n chars of t with s*/
int strncmp(char *s, char *t, int n)
{
    for (; *s == *t; s++, t++)
    {
        if (*s == '\0' || --n <= 0)
        {
            return 0;
        }
    }
    return *s - *t;
}