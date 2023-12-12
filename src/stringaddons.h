#include <string>
#include <stdio.h>
#include "deftypes.h"
using namespace std;
/// @brief string built with C to help some features.
class _str
{
public:
    // get length of this object
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
    }
    char arr[INT32_MAX];

private:
};
char *itoa(_int64 num)
{
    char *str = new char[100];
    int it = 0;
    while (num)
    {
        str[it++] = num % 10;
        num /= 10;
    }
    return str;
}
// char *itoa(_int32 num)
// {
//     char *str = new char[100];
//     int it = 0;
//     while (num)
//     {
//         str[it++] = num % 10;
//         num /= 10;
//     }
//     return reverse(str, it);
// }