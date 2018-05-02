#include <stdio.h>

/*print Celsius-Fahrenheit table*/
int e1_4main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius Fahr\n");
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = 9.f * celsius / 5.f + 32.f;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}
