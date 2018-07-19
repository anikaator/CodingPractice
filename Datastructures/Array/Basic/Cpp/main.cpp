#include <iostream>
#include <array>

using namespace std;

int main() {

    //Initializing array to global will zero initialized
    array<int,10> try_arr global;
    for (auto &x : try_arr) {
        x = rand()%100;
    }

    //Display
    cout << "My array contains :" << endl;
    for (auto &x : try_arr) {
        cout << &x << " -  " << x << endl;
    }

    cout << "first location has : " << try_arr.front() << endl;
    cout << "Fifth location has : " << try_arr[4] << endl;
    cout << "Seventh location has : " << try_arr.at(7-1) << endl;
    cout << "Max size is : " << try_arr.max_size() << endl;
    
    array<int, 10> another_arr = { 1, 2, 3, 4, 5 };

    try_arr.swap(another_arr);

    cout << "After swapping array contains :" << endl;
    for (auto it = try_arr.begin(); it != try_arr.end(); it++) {
        cout << it << " - " << *it << endl;
    }
    return 0;
}
