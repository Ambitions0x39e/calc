#include <iostream>
#include <algorithm>
using namespace std;
double table[2][1024];
/*
This program is a calculator for the expectation and variance of a probability distribution.
The distribution is a table of two parts, the first part is the x part, the second part is the p part.
The x part is a list of index, the p part is a list of possibilities.
The program will calculate the expectation and variance of the distribution.
The program will use the table to calculate the expectation and variance.
*/
int main()
{
    int table_length;
    cout << "pls input the table length" << endl;
    cin >> table_length;
    cout << "pls input the x part" << endl;
    for (int i = 0; i < table_length; i++)
    {
        cin >> table[0][i];
    }
    cout << "pls input the p part" << endl;
    for (int i = 0; i < table_length; i++)
    {
        cin >> table[1][i];
    }
    double expectation = 0;
    for (int i = 0; i < table_length; i++)
    {
        expectation += table[0][i] * table[1][i];
    }
    cout << "the expectation is: " << expectation << endl;
    double variance = -(expectation * expectation);
    for (int i = 0; i < table_length; i++)
    {
        variance += table[0][i] * table[0][i] * table[1][i];
    }
    cout << "the variance is: " << variance << endl;
    return 0;
}
