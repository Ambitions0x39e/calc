#include "stdio.h"
#define _int64 long long
_int64 QuickPow(_int64 x, _int64 n)
{
    if (n == 0)
    {
        return 1;
    }
    _int64 res = QuickPow(x, n / 2);
    if (n % 2)
    {
        return res * res * x;
    }
    else
    {
        return res * res;
    }
}
/*
TODO:
- Permutation support
    - Check if Permutation can run
- Combination support
    - _int64per
*/
// This function is for calculating permutation nPm under the usage of _int64 number.
_int64 Permutation(_int64 n, _int64 m)
{
    _int64 result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    for (int i = 2; i <= (n - m); i++)
    {
        result /= i;
    }
    return result;
}

_int64 Combination(_int64 n, _int64 m) 
{
    _int64 result = Permutation(n,m);
    for (int i = 2; i <= m; i++)
    {
        result /= i;
    }
    return result;
}
/*

*/