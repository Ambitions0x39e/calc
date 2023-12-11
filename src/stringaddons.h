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
        int len = self->length();

        for (int i = 0, j = len - 1; i < j; i++, j--)
        {
            // swap characters at indexes i and j
        }
    }

    void itoa()
    {
    }

private:
    char arr[INT32_MAX];
};
char *reverse(char *str, int len)
{
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        swap(str[i], str[j]);
    }
    return str;
}
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
char *itoa(_int32 num)
{
    char *str = new char[100];
    int it = 0;
    while (num)
    {
        str[it++] = num % 10;
        num /= 10;
    }
    return reverse(str, it);
}