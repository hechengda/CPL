/*expand newline and tab into visible seq while copying t to s*/
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\n':      /*newline cahr*/
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':      /*tab char*/
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:        /*other chars*/
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

/*convert escape seq into real chars while copying t to s*/
void unescape1(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
    {
        if (t[i] != '\\')
        {
            s[j++] = t[i];
        }
        else
        {/* it's backslash*/
            switch (t[++i])
            {
            case 'n':       /*real newline*/
                s[j++] = '\n';
                break;
            case 't':       /*real tab*/
                s[j++] = '\t';
                break;
            default:        /*other chars*/
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
        }
    }
    s[j] = '\0';
}

void unescape2(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\\':      /*backslash*/
            switch (t[++i])
            {
            case 'n':       /*real newline*/
                s[j++] = '\n';
                break;
            case 't':       /*real tab*/
                s[j++] = '\t';
                break;
            default:        /*other chars*/
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
            break;
        default:        /*not backslash*/
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}
