#include <stdio.h>

void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
    {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

void qsort(int v[], int l, int r)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (l >= r)
    {
        return;
    }
    swap(v, l, (l + r) / 2);
    last = l;
    for (i = l + 1; i <= r; i++)
    {
        if (v[i] < v[l])
        {
            swap(v, i, ++last);
        }
    }
    swap(v, l, last);
    qsort(v, l, last - 1);
    qsort(v, last + 1, r);
}

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
