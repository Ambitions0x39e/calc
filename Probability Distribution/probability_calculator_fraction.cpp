#include <iostream>
#include <algorithm>
using namespace std;
/*
this struct provides with a new type FRACTION, in the struct it provides 3 functions: 
    __print(): prints the FRACTION with the structure " %d / %d"
    __init(): initialises the FRACTION with the given parameters
    simplify(): simplifies the FRACTION
also defined following fucntions:
    add(): adds two FRACTIONS and returns the result
    multiply(): multiplies two FRACTIONS and returns the result
*/
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
typedef struct frac
{
    // numerator -> 分子
    // denominator -> 分母
    int numerator, denominator;
    void simplify()
    {
        int _selfGCD = gcd(numerator, denominator);
        numerator /= _selfGCD, denominator /= _selfGCD;
    }
    void __init(int numa, int numb)
    {
        numerator = numa;
        denominator = numb;
    }
    void __print()
    {
        printf("%d/%d", numerator, denominator);
    }
} FRAC;
FRAC newNode(int nume, int deno)
{
    FRAC p;
    p.__init(nume, deno);
    return p;
}
FRAC add(FRAC a, FRAC b)
{
    FRAC sum;
    sum.denominator = a.denominator * b.denominator;
    sum.numerator = a.denominator * b.numerator + b.denominator * a.numerator;
    sum.simplify();
    return sum;
}
FRAC multiply(FRAC a, FRAC b)
{
    FRAC sum;
    sum.__init(a.numerator * b.numerator, a.denominator * b.denominator);
    sum.simplify();
    return sum;
}
int table[1024];
FRAC prob[1024];
int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    FRAC fa,fb;
    fa.__init(a,b);
    fb.__init(c,d);
    FRAC fc;
    fc = multiply(fa,fb);
    fc.__print();
    return 0;
}
// int main()
// {
//     int table_length;
//     cout << "pls input the table length" << endl;
//     cin >> table_length;
//     cout << "pls input the x part" << endl;
//     for (int i = 0; i < table_length; i++)
//     {
//         cin >> table[0];
//     }
//     cout << "pls input the p part" << endl;
//     for (int i = 0; i < table_length; i++)
//     {
//         scanf("%d/%d", &prob[i].numerator, &prob[i].denominator);
//     }
//     FRAC expectation;
//     expectation.__init(1, 1);
//     for (int i = 0; i < table_length; i++)
//     {
//         FRAC temp;
//         temp.__init(table[i] * prob[i].numerator, prob[i].denominator);
//         temp.simplify();
//         expectation = add(expectation, temp);
//     }
//     return 0;
// }
