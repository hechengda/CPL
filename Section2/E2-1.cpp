#include <stdio.h>
#include <limits.h>

/*determine ranges of types*/
int main()
{
    /*signed types*/
    printf("signed char min     = %d - %d\n", SCHAR_MIN, -(char)((unsigned char) ~0 >> 1) - 1);
    printf("signed char max     = %d - %d\n", SCHAR_MAX, (char)((unsigned char) ~0 >> 1));
    printf("signed short min    = %d\n", SHRT_MIN);
    printf("signed short max    = %d\n", SHRT_MAX);
    printf("signed int min      = %d\n", INT_MIN);
    printf("signed int max      = %d\n", INT_MAX);
    printf("signed long min     = %ld\n", LONG_MIN);
    printf("signed long max     = %ld\n", LONG_MAX);

    /*unsigned types*/
    printf("unsigned char max   = %u - %u\n", UCHAR_MAX, (unsigned char) ~0);
    printf("unsigned short max  = %u\n", USHRT_MAX);
    printf("unsigned int max    = %u\n", UINT_MAX);
    printf("unsigned long max   = %lu\n", ULONG_MAX);

    return 0;
}
