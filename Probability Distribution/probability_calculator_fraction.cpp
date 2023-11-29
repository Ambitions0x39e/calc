#include <iostream>
#include <algorithm>
#include "../src/fractions.h"
using namespace std;
int table[1024];
fractions prob[1024];
int main()
{
    int table_length;
    cout << "Pls input the table length" << endl;
    cin >> table_length;
    cout << "Pls input the x part" << endl;
    for (int i = 0; i < table_length; i++)
    {
        cin >> table[i];
    }
    cout << "Pls input the p part" << endl;
    for (int i = 0; i < table_length; i++)
    {
        prob[i].__input();
        // prob[i].__print();
        // cout<<' ';
    }
    cout << endl;
    fractions expectation;
    expectation.__init(0, 1);
    for (int i = 0; i < table_length; i++)
    {
        fractions t = newNode(table[i], 1) * prob[i];
        // t.__print();
        expectation = expectation + t;
        expectation.simplify();
        // expectation.__print();
        // cout << ' ';
    }
    cout << "The expectation is: ";
    expectation.__print();
    cout << ". The real number for expectation is ";
    expectation.__print_real();
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
    cout << ". the float number of variance is: ";
    variance.__print_real();
    return 0;
}