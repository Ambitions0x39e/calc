#include <iostream>
#include <algorithm>
#include "../fractions.h"
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
int table[1024];
fractions prob[1024];
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
    fractions expectation;
    expectation.__init(0, 1);
    for (int i = 0; i < table_length; i++)
    {
        fractions t= newNode(table[i], 1) * prob[i];
        // t.__print();
        expectation = expectation + t;
        expectation.simplify();
        // expectation.__print();
        // cout << ' ';
    }
    cout << "the expectation is: ";
    expectation.__print();
    cout << endl;

    fractions variance = expectation * expectation;
    variance.numerator *= -1;
    for (int i = 0; i < table_length; i++)
    {
        fractions t;
        t.__init(1, 1);
        fractions tmp;
        tmp.__init(table[i], 1);
        // tmp.__print();
        // cout<<' ';
        t = t * newNode(table[i], 1);
        t = t * newNode(table[i], 1);
        t = t * prob[i];
        variance = variance + t;
        variance.simplify();
        // variance.__print();
        // cout<<' ';
    }
    cout << endl;
    expectation.__print();
    cout << endl;
    cout << "the variance is: ";
    variance.__print();
    return 0;
}