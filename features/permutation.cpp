#include <iostream>
#include "../src/mathalgo.h"
#include "../src/deftypes.h"
using namespace std;
int main() {
    _int64 n,m;
    cerr<<"Please input n and m"<<endl;
    cin>>n>>m;
    cout<<_permutation(n,m);
}