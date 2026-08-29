#include <iostream>
using namespace std;

int main(){
    int n , i,j;
    cout << "Enter the size of pattern";
    cin >> n;

    for(i = 0;i<n; i++){

        // TOP Part of pattern
        for(j=0;j<n-i-1;j++){
            cout << " ";
        }
        cout << "*";
        if(i != 0){
            for(j=0;j<2*i-1;j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    
    // BOTTOM Part
    for(i=0;i<n-1;i++){

        // Space 

        for(j=0;j<i+1;j++){
            cout << " ";
        }
        cout << "*";

        if(i != n-2){

            //Space 

            for(j=0;j<(2*(n-i)-5);j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }

        
    return 0;
}
