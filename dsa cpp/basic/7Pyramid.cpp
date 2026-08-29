#include<iostream>
using namespace std;
int main(){

    int n,i,j,k,l;
    cout << "Enter no.";
    cin >> n;

    for(i=0;i<n;i++){
        // space
        for(j=0;j<n-i-1;j++){
            cout << " ";
        }
        // for num1 
        for(j=1;j<=i+1;j++){
            cout << j;
        }
        // for num 2
        for(j=i;j>0;j--){
            cout << j;
        }
        cout << endl;

    }
    return 0;
}