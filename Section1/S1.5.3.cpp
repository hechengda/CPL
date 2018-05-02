#include <stdio.h>

int s1_5_3main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nl;
    }
    printf("%d\n", nl);

    return 0;
}
