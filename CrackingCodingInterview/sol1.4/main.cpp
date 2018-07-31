#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        bool check_permutation_palindrome(string str) {
            int single_ctr = 0;
            bool arr[256] = {false};

            for (auto &x : str) {
                if (arr[x] == false) {
                    single_ctr++; 
                    arr[x] = true;
                }
                else {
                    single_ctr--; 
                    arr[x] = false;
                }
            }
            if (single_ctr == 0  || single_ctr == 1)
                return true;
            else
                return false;
        }
};

int main() {

    string str;
    cout << "Enter string to be checked: ";
    cin >> str;
    bool ret = Solution().check_permutation_palindrome(str);
    if (ret == true)
        cout << "String is permutation palindrome";
    else
        cout << "String is not permutation palindrome";
    return 0;
}
