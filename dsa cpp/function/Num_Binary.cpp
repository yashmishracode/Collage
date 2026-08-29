#include <iostream>
using namespace std;


int NumBin(int num){
    int ans =0,pow =1;
    while (num > 0){
        int rem = num % 2;
        num /= 2;

        ans += (rem * pow);
        pow *=10;
    }
    return ans;
}

int BinNum(int b){
    int ans =0,pow=1;
    while (b>0){
        int rem = b % 2;
        ans += (rem *pow);

        b /= 10;
        pow *=2;
    }
    return ans;
}
int main(){

    int a = 50;
    int b = 1010110;
    cout << NumBin(a) << endl;

    cout << BinNum(b) << endl;
    return 0;
}