#include<iostream>
using namespace std;

int main(){

    int n , i , j;
    cout << "Enter no.";
    cin >> n;

    // star triangle
    // for(i=0;i<n;i++){
    //     for(j=0;j<=i;j++){
    //         cout << "*" << " ";
    //     }
    //     cout  << endl;
    // }

    // for number
    // int num =1;
    // for(i=0;i<n;i++){
    //     for(j=0;j<=i;j++){
    //         cout << num << " ";
    //     }
    //     num+=1;
    //     cout << endl;
    // }

    // method 2
    // int num =1;
    // for(i=0;i<n;i++){
    //     for(j=0;j<=i;j++){
    //         cout << i+1 << " ";
    //     }
    //     cout << endl;
    // }

    // for letters
    // char ch ='A';
    // for(i=0;i<n;i++){
    //     for(j=0;j<=i;j++){
    //         cout << ch << " ";
    //     }
    //     ch+=1;
    //     cout << endl;
    // }

    // for progressive int in each line
    // for(i=0;i<n;i++){
    //     int num =1;
    //     for(j=0;j<=i;j++){
    //         cout << num << " ";
    //         num+=1;
    //     }
    //     cout << endl;
    // }
    // better method
    // for(i=0;i<n;i++){
    //     for(j=0;j<=i;j++){
    //         cout << j+1 << " ";
    //     }
    //     cout << endl;
    // }

    // Now reverse of the above code

    // for(i=0;i<n;i++){
    //     for(j=i+1;j>0;j--){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    
    // floids triangle pattern
    int num = 1;
    for(i=0;i<n;i++){
        for(j=i+1;j>0;j--){
            cout << num << " ";
            num+=1;
        }
        cout << endl;
    }


    return 0;
}