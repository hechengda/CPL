#include <stdio.h>

int s1_2main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    /*E1-3*/
    /*printf("Fahr Celsius\n");*/
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5.f * (fahr - 32.f) / 9.f;
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
