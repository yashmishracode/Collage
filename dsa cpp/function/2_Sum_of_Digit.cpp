#include <iostream>
using namespace std;

void digitSum(int x){
    int sum = 0;
    while (x >0 ){
        int last = x%10;
        x = x/10;
        sum += last;
    }
    cout << sum << endl;
}

int main (){
    digitSum(123421);
    return 0;
}