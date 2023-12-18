#include <iostream>
#include <vector>
using namespace std;
double arr[1024];
int main() {
    int n;
    cerr<<"Pls input the length of the array: ";
    cin>>n;
    cout<<"Now, pls input the content of the array: "<<endl;
    for(int i=0; i<n; i++) { 
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0; i<n; i++) {
        cerr<<arr[i]<<" ";
    }
    cerr<<endl;
    return 0;
}