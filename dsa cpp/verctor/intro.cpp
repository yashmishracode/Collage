#include <iostream>
#include <vector>
using namespace std;

int main (){
    vector<int> vec1; // size = 0
    // or 
    vector<int> vec2 = {1,2,3}; // size = 3
    cout  << vec2[1] << endl;
    // or 
    vector<int> vec3 (5,0); // vecot of size 5 with zero value
    cout  << vec3[1] << endl;

    return 0;
}