#include "stdio.h"
#include "algorithm"
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
class fractions
{
public:
    // numerator -> 分子
    // denominator -> 分母
    int numerator, denominator;
    void simplify()
    {
        int _selfGCD = gcd(numerator, denominator);
        numerator /= _selfGCD, denominator /= _selfGCD;
        correctOrder();
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
    void __input()
    {
        scanf("%d/%d", &numerator, &denominator);
    }

private:
    void correctOrder()
    {
        if (denominator < 0 && numerator > 0)
        {
            denominator *= -1;
            numerator *= -1;
        }
    }
};
fractions newNode(int nume, int deno)
{
    fractions p;
    p.__init(nume, deno);
    return p;
}
fractions add(fractions a, fractions b)
{
    fractions sum;
    sum.denominator = a.denominator * b.denominator;
    sum.numerator = a.denominator * b.numerator + b.denominator * a.numerator;
    sum.simplify();
    return sum;
}
fractions multiply(fractions a, fractions b)
{
    fractions sum;
    sum.__init(a.numerator * b.numerator, a.denominator * b.denominator);
    sum.simplify();
    return sum;
}