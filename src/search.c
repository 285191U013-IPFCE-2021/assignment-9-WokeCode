#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x)
{
    if (n == 0) 
        return false;
    if (n > 0 && a[n - 1] == x)
        return true;
    if (n > 0 && a[n - 1] != x)
        return search(a, n - 1, x);
}
