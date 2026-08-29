#include <iostream>
using namespace std;

int fact(int x){
    int fac = 1;
    for (int i = 1 ; i<=x;i++){
        fac *=i;
    }
    return fac;
}
int main (){
    int n = 12, r =4;
    cout << "nCr = " << fact(n)/(fact(r)*fact(n-r)) << endl; 
    return 0;
}