#include<iostream>
using namespace std;

int main(){

    int a;
    cout << "Enter No. You want to check\n";
    cin >> a;
    
    if (a%2==0){
        cout << "Even";
    }
    else{
        cout << "Odd";
    }

    return 0;
}