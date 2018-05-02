#include <stdio.h>

float celsius(float fahr);

int e1_15main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    /*E1-3*/
    /*printf("Fahr Celsius\n");*/
    fahr = lower;
    while (fahr <= upper)
    {
        printf("%3.0f %6.1f\n", fahr, celsius(fahr));
        fahr = fahr + step;
    }

    return 0;
}

float celsius(float fahr)
{
    return (5.f / 9.f) * (fahr - 32.f);
}
