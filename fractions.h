#include "stdio.h"
#include "algorithm"
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
class fractions
{
public:
    // numerator -> 分子     denominator -> 分母
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
    // re-define operator for `class fractions` : addition
    fractions operator+(const fractions &b) const
    {
        fractions result;
        result.denominator = this->denominator * b.denominator;
        result.numerator = this->denominator * b.numerator + b.denominator * this->numerator;
        result.simplify();
        return result;
    }
    // re-define operator for `class fractions` : multiplication
    fractions operator*(const fractions &b) const
    {
        fractions result;
        result.denominator = this->denominator * b.denominator;
        result.numerator = this->numerator * b.numerator;
        result.simplify();
        return result;
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
