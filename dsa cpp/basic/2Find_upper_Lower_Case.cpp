#include<iostream>
using namespace std;

int main(){
    char ch;
    cout << "Enter a char to check if it's Upper or Lower case\n";
    cin >> ch;
    // Method -1 
    if((ch>='a') && (ch <= 'z')){
        cout << "Lower Case Letter";
    }
    else if((ch>='A') && (ch <= 'Z')){
        cout << "Upper Case Letter";
    }

    // method -2
    // if ((ch>=65)&&(ch<=90)){
    //     cout << "Upper Case";
    // }

    return 0;
}