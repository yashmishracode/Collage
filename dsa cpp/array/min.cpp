#include <iostream>
#include <climits>
using namespace std;

int main (){

    int arr[5]= {12,34,42,231,0};
    int smallest =  INT_MAX;
    for(int i =0;i<5;i++){
        smallest = min(arr[i],smallest);
        // if (arr[i]<smallest){
        //     smallest = arr[i];
        // }
    }
    cout << smallest;
    return 0;
}