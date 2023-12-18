#include <string.h>
#include <stdio.h>
#include "deftypes.h"
using namespace std;
/// @brief string built with C to help some features.
/*
TODO: 
- atoi ?
- a to cxx_string
*/
class _str
{
public:
    // get length of this object
    void edit_full(char str[])
    {
        for (int i = 0; i < strlen(str); i++)
        {
            arr[i] = str[i];
        }
    }
    int length()
    {
        return strlen(arr);
    }
    void reverse()
    {
        for (int i = 0, j = length(); i < j; i++, j--)
        {
            // swap characters at indexes i and j
            swap(arr[i], arr[j]);
        }
    }
    // integer to ascii, available for both _int64 (long long) and _int32(int)
    void itoa(_int32 num)
    {
        while (num)
        {
            arr[length()] = num % 10;
            num /= 10;
        }
    }
    void itoa(_int64 num)
    {
        while (num)
        {
            arr[length()] = num % 10;
            num /= 10;
        }
        reverse();
    }
    char arr[2<<20];
};