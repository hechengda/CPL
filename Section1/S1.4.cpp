#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

int s1_4main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.f / 9.f) * (fahr - 32));
    }

    return 0;
}
