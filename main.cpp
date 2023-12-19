#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sys/utsname.h>
#include "src/date.h"
using namespace std;
int main() {
    utsname tmp;
    uname(&tmp);
    string sysName=tmp.sysname;
    date now;
    now.__init();
    system("sleep 1");
    cerr<<"Simple Calculator for Equations"<< "-version:"<<" 0.2.0 Beta"<<endl;  
    now.print();
    cerr<<", System: "<<sysName<<endl;
    cerr<<"Type exit() or quit() to exit the program."<<endl;
    string prompt;
    while(1) {
        cout<<">>>";
        getline(cin,prompt);
        // Detect if the input is EOF
        if(cin.eof()) {
            cerr<<"END";
            return 0;   
        }
        // Detect if the input is ^l or clear
        if(prompt=="clear" || prompt=="^L") {
            system("clear");
        }
        if(prompt=="exit()" || prompt=="quit()" || prompt=="exit" || prompt=="quit" || prompt=="^D") {
            break;
        } else if(prompt=="Probability Distribution Fraction") {
            system("./exes/probability_calculator_fraction");
            cout<<endl;
        } else if(prompt=="Probability Distribution Float") {
            system("./exes/probability_calculator_float");
            cout<<endl;
        } else if(prompt=="sort") {
            system("./exes/sort-files");
        } else if(prompt=="variance") {
            system("./exes/variance");
        } else {
            cerr<<"Invalid Input"<<endl;
        }
    }    
}