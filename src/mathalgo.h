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
    - _int64
- Combination support
    - _int64
    
*/
_int64 Permutation(_int64 n, _int64 m)
{
    _int64 result=1;
    for(int i=0;i<m;i++) {
        
    }
}