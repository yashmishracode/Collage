#include <iostream>
# include <vector>

using namespace std;

int main (){
    vector<int> vec = {1,2,3,4};

    cout << "Size = " << vec.size() << endl; // check size
    vec.push_back(23); // push element 
    cout << "Size = " << vec.size() << endl;
    vec.pop_back(); // pop element 
    cout << "front = " << vec.front() << endl;
    cout << "back = " << vec.back() << endl;
    cout << "Value at 3 = " << vec.at(3) << endl;


    for(int val : vec){ // for each loop
        cout << val << endl;
    }
    return 0;
}