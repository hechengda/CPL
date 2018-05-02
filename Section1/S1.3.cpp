#include <stdio.h>

int s1_3main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    {
        printf("%3d %6.1f\n", fahr, (5.f / 9.f) * (fahr - 32));
    }

    return 0;
}
