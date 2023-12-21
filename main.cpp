#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sys/utsname.h>
#include "src/date.h"
#include "src/versions.h"
#include "src/mathalgo.h"
using namespace std;
int main() {
    utsname tmp;
    uname(&tmp);
    string sysName=tmp.sysname;
    date now;
    now.__init();
    system("sleep 1");
    cerr<<"Simple Calculator for Equations"<< "-version:"<<__VERSIONS__OF__PROG<<endl;  
    now.print();
    cerr<<", on system: "<<sysName<<endl;
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
        // Detect if the input is ^L or clear
        size_t ctrlPos = prompt.find("Ctrl");
        size_t lPos = prompt.find("L");
         if(prompt=="\f" || prompt=="clear") {
            system("clear");
        } else if(prompt=="exit()" || prompt=="quit()" || prompt=="exit" || prompt=="quit" || prompt=="^D") {
            break;
        } else if(prompt=="PD: Fraction") {
            system("./exes/probability_calculator_fraction");
            cout<<endl;
        } else if(prompt=="PD: Float") {
            system("./exes/probability_calculator_float");
            cout<<endl;
        } else if(prompt=="sort") {
            system("./exes/sort-files");
        } else if(prompt=="variance") {
            system("./exes/variance");
        } else if(prompt=="combination") {
            system("./exes/combination");
        } else if(prompt=="permutation") {
            system("./exes/permutation");
        } else {
            cerr<<"Invalid Input"<<endl;
        }
    }    
}