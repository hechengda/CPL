#include <stdio.h>

/*count blanks, tabs and newlines*/
int e1_8main()
{
    int c, nb, nt, nl;

    nb = nt = nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    }
    printf("%d %d %d\n", nb, nt, nl);

    return 0;
}
