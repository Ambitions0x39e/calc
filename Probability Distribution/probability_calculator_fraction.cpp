#include <iostream>
#include <algorithm>
using namespace std;
/*
this struct provides with a new type FRACTION, in the struct it provides 3 functions:
    __print(): prints the FRACTION with the structure " %d / %d"
    __init(): initialises the FRACTION with the given parameters
    simplify(): simplifies the FRACTION
    correctOrder(): corrects the order of the FRACTION, if the denominator is negative and the numerator is positive, it will change the order
        Note: the function simplify() calls correctOrder(), which is combined into one step.
also defined following functions:
    add(): adds two FRACTIONS and returns the result
    multiply(): multiplies two FRACTIONS and returns the result
    newNode(): creates a new FRACTION with the given parameters 
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
    void __input()
    {
        scanf("%d/%d", &numerator, &denominator);
    }
    void correctOrder() {
        if(denominator<0 && numerator>0) { 
            denominator*=-1;
            numerator*=-1;
        }
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
int main()
{
    int table_length;
    cout << "pls input the table length" << endl;
    cin >> table_length;
    cout << "pls input the x part" << endl;
    for (int i = 0; i < table_length; i++)
    {
        cin >> table[i];
    }
    cout << "pls input the p part" << endl;
    for (int i = 0; i < table_length; i++)
    {
        scanf("%d/%d", &prob[i].numerator, &prob[i].denominator);
        // prob[i].__print();
        // cout<<' ';
    }
    cout << endl;
    FRAC expectation;
    expectation.__init(0, 1);
    for (int i = 0; i < table_length; i++)
    {
        FRAC t = multiply(newNode(table[i], 1), prob[i]);
        // t.__print();
        expectation = add(expectation, t);
        expectation.simplify();
        // expectation.__print();
        // cout << ' ';
    }
    cout << "the expectation is: ";
    expectation.__print();
    cout << endl;

    FRAC variance = multiply(expectation, expectation);
    variance.numerator *= -1;
    for (int i = 0; i < table_length; i++)
    {
        FRAC t;
        t.__init(1,1);
        FRAC tmp;
        tmp.__init(table[i], 1);
        // tmp.__print();
        // cout<<' ';
        t=multiply(t,newNode(table[i],1));
        t=multiply(t,newNode(table[i],1));
        t=multiply(t,prob[i]);
        variance=add(variance,t);
        variance.simplify();
        variance.correctOrder();
        // variance.__print();
        // cout<<' ';
    }
    cout<<endl;
    cout<<"the variance is: ";
    variance.__print();
    return 0;
}