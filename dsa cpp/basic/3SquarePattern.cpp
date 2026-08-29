#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the no for pattern";
    cin >> n;

    // for(int i = 0; i<n; i++){
    //     for(int j=0;j<n;j++){
    //         cout << j+1 << " ";
    //     }
    //     cout << endl;
    // }

    // // for alphabatical value
    // for(int i = 0; i<n; i++){
    //     char ch = 'A';
    //     for(int j=0;j<n;j++){
    //         cout << ch << " ";
    //         ch+=1;
    //     }
    //     cout << endl;
    // }

    // for increasing pattern
    // int count =1;
    // for(int i = 0; i<n; i++){
    //     for(int j=0;j<n;j++){
    //         cout << count << " ";
    //         count+=1;
    //     }
    //     cout << endl;
    // }


    // For char too
    char count ='a';
    for(int i = 0; i<n; i++){
        for(int j=0;j<n;j++){
            cout << count << " ";
            count+=1;
        }
        cout << endl;
    }

    return 0;

}
