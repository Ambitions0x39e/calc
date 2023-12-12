#include <string>
#include <stdio.h>
#include "deftypes.h"
using namespace std;
class _str
{
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
    void itoa()
    {
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