#include "stdio.h"
#include "algorithm"

/*
this class provides with a new datatype FRACTION, in the struct it provides 3 functions:
    __print(): prints the FRACTION with the structure " %d / %d"
    __init(): initialises the FRACTION with the given parameters
    simplify(): simplifies the FRACTION
    correctOrder(): corrects the order of the FRACTION, if the denominator is negative and the numerator is positive, it will change the order
        Note: the function simplify() calls correctOrder(), which is combined into one step.
    the class itself also re-defines four operator: '+', '-', '*', '/'
also defined following functions:
    newNode(): creates a new FRACTION with the given parameters, creating 0/1 in default
*/
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
    void __input()
    {
        scanf("%d/%d", &numerator, &denominator);
    }
    void __print()
    {
        printf("%d/%d", numerator, denominator);
    }
    void __print_real() {
        printf("%.3lf", (double)((double)numerator/denominator));
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
    // re-define operator for `class fractions` : subtraction
    fractions operator-(const fractions &b) const
    {
        fractions result;
        result.denominator = this->denominator * b.denominator;
        result.numerator = this->denominator * b.numerator - b.denominator * this->numerator;
        result.simplify();
        return result;
    }
    // re-define operator for `class fractions` : division
    fractions operator/(const fractions &b) const
    {
        fractions result;
        result.denominator = this->denominator * b.numerator;
        result.numerator = this->numerator * b.denominator;
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
fractions newNode(int nume = 0, int deno = 1)
{
    fractions p;
    p.__init(nume, deno);
    return p;
}
class fakeFraction : public fractions
{
    int _coefficient;
    void __init(int coef, int numa, int numb)
    {
        _coefficient = coef;
        numerator = numa;
        denominator = numb;
    }
    void __input()
    {
        int number;
        scanf("%d+%d/%d", &number, &numerator, &denominator);
    }
    void __print()
    {
        printf("%d+%d/%d", numerator / denominator, numerator % denominator, denominator);
    }
};
