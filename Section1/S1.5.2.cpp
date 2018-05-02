#include <stdio.h>

int s1_5_2main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
    {
        ++nc;
    }
    printf("%ld\n", nc);

    return 0;
}
