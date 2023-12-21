#include "stdio.h"
#include "deftypes.h"
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
///@brief This function is for calculating permutation nPm under the usage of _int64 number.
///@param n The total number. 
///@param m The number of selection.
///@return The permutation result, in _int64 structure.
_int64 _permutation(_int64 n, _int64 m)
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
///@brief This function is for calculating combination nCm under the usage of _int64 number.
///@param n The total number.
///@param m The number of selection.
///@return The combination result, in _int64 structure.
_int64 _combination(_int64 n, _int64 m) 
{
    _int64 result = _permutation(n,m);
    for (int i = 2; i <= m; i++)
    {
        result /= i;
    }
    return result;
}
_int64 Factorial(_int64 n) {
    _int64 result = 1;
}
/*

*/