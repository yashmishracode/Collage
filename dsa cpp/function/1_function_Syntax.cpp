#include <iostream>
using namespace std;

int hello(){
    cout << "Hello\n";
    return 3l;
}

int sum(int a , int b){
    return a+b;
}
int main (){
    cout << hello() << endl;
    cout << sum(23,34) << endl;
}