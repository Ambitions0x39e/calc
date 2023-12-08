#include "iostream"
#include "math.h"
using namespace std;
/*
rx=sqrt(x)
rxs=sqrt(x^2)
n=n
rxms=sqrt(x-mean)^2
*/
int main()
{
    double rx, rxs, n, rxms = -1;
    string command;
    do
    {
        cin >> command;
        if (command == "rx")
        {
            cin >> rx;
        }
        else if (command == "rxs")
        {
            cin >> rxs;
        }
        else if (command == "n")
        {
            cin >> n;
        }
        else if (command == "rxms")
        {
            cin >> rxms;
        }
    } while (command != "END");
    double standardDeviation;
    if (rxms == -1)
    {
        standardDeviation = sqrt(rxs / n - (rx / n) * (rx / n));
        cout << standardDeviation;
    }
    else
    {
        standardDeviation = sqrt(rxms / n);
        cout << standardDeviation;
    }
    return 0;
}