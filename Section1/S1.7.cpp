#include <stdio.h>

int power(int base, int n);

int s1_7main()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

int power(int base, int n)
{
    int p = 1;
    while (n--)
    {
        p *= base;
    }
    return p;
}
