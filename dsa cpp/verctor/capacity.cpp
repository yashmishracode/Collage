#include <iostream>
# include <vector>

using namespace std;

int main (){
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(23);
    vec.push_back(45);

    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    return 0;
}