#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    string str = "abcdeafgg%39%^9";

    cout << "First solution O(n^2):"\
            "\nTake one character and traverse all the way to check dup";
    bool found = false;
    for(auto it = str.begin(); it != str.end() - 1; it++) {
        for (auto it2 = it + 1; it2 != str.end(); it2++) {
            if (*it == *it2) {
                cout << "\nMatch found : " << distance(str.begin(), it) + 1 << ":" << distance(str.begin(), it2) + 1;
                found = true;
                break;
            }
            //if (found == true) break;
        }
    }


    cout << "\n\nSecond solution O(n + nlogn):"\
            "\nSort array and check if next element is same";

    sort(str.begin(), str.end());
    for (auto it = str.begin(); it != str.end() - 1 ; it++) {
        //cout << "\nComparing :" << *it << "-" << *(it + 1 );
        if (*it == *(it + 1)) {
            cout << "\nDup found!! : " << *it;
        }
    }

    cout << "\n\nThird solution O(N) but using extra space for bit comparison";
    static int checker[8] = {0};
    for (auto it = str.begin(); it != str.end(); it++) {
        int pos = (*it) / 32;
        int mod = (*it) % 32;
        if ((checker[pos] & (1 << mod)) > 0) {
            cout << "\nDup :" << *it;
        }
        checker[pos] |= (1 << mod);
    }
    return 0;
}

