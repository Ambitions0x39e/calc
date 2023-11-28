#include "stdio.h"
#define _int64 long long
long long QuickPow(_int64 x, _int64 n)
{
    if (n == 0)
    {
        return 1;
    }
    _int64 res=QuickPow(x, n / 2);
    if (n % 2)
    {
        return res * res * x;
    }
    else
    {
        return res * res;
    }
}