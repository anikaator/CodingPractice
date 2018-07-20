#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    auto print = [](const int& n) { cout << " " << n; }; 
    vector<int> my_vec;
    for (int i; i <= 10; i++) my_vec.push_back(rand()%100);

    for (auto &x : my_vec) cout << " " << x;

    cout << "\nReverse printing : ";
    for (auto it = my_vec.rbegin(); it != my_vec.rend(); ++it) {
        cout << " " << *it;
    }

    cout << "\nCurrent capacity is : " << my_vec.capacity() << endl;
    cout << "Current size is : " << my_vec.size() << endl;
    my_vec.resize(8);
    my_vec.shrink_to_fit();
    cout << "Shrinked to size 8 :";
    for_each (my_vec.begin(), my_vec.end(), print);
    cout << "\nReference operator [2] : = " << my_vec[2];

    cout << "\nat : my_vec.at(4) = " << my_vec.at(4);

    cout << "\nfront() : my_vec.front() = " << my_vec.front();

    cout << "\nback() : my_vec.back() = " << my_vec.back();

    my_vec.emplace_back(88);
    cout << "\nemplace_back(88) : inserting to end ";
    for (auto it = my_vec.begin(); it != my_vec.end(); ++it) {
        cout << " " << *it;
    }

    my_vec.erase(my_vec.begin());
    cout << "\nremove first element my_vec.erase(my_vec.begin()) ";
    for (auto it = my_vec.begin(); it != my_vec.end(); ++it) {
        cout << " " << *it;
    }

    my_vec.insert(my_vec.begin(), 99);
    cout << "\nmy_vec.insert(my_vec.begin(), 99) : inserting to 99 to start";
    for (auto it = my_vec.begin(); it != my_vec.end(); ++it) {
        cout << " " << *it;
    }
    return 0;
}
