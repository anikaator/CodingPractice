#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums2 = nums;
    int count = 0;
    auto marks = nums.begin();
    for (auto it = nums.begin(); it != nums.end(); it++) {
        *marks = *it;
        marks++;
        count++;
        while (*it == *(it+1) && (it+1) != nums.end()) {
            it++;
        }
    }
    cout << "\nSize1 :" << count <<endl;
    for (auto &x : nums){ 
        if (--count < 0) 
            break;  
        cout << x;
    }


    for (auto it = nums2.begin(); it != nums2.end(); ++it) {
        while (*it == *(it+1) && (it+1) != nums2.end()) {
            nums2.erase(it);
        }
    }
    cout << "\nSize2 : " << nums2.size();
    return 0;
}
