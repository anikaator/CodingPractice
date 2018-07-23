#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

void using_hash(string str1, string str2) {
    map <char, int> hash_map;
    for (auto &ch : str1) {
        auto ret = hash_map.insert(pair<char, int> (ch, 1));
        if (ret.second == false) {
            ret.first->second++;
        }
    }

    for (auto &ch : str2) {
        auto it = hash_map.find(ch);
        if (it == hash_map.end()) {
            cout << "Two strings are not permutation is each others";
            return;
        }
        if (it->second > 1) {
            it->second--;
        } else {
            hash_map.erase(it);
        }
    }
    if (hash_map.empty() == true) {
        cout << "Two strings are permutation is each others";
    } else {
        cout << "Two strings are not permutation is each others";
    }

}

void using_sort(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1.size() != str2.size()) {
        cout << "\nSize not matching so not a permutation";
        return;
    }

    for (int i=0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            cout << "\nTwo strings are not permutation is each others";
            return;
        }
    }
    cout << "\nTwo strings are permutation is each others";
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Invalid input!!" << endl;
        return 0;
    }

    string str1 = argv[1];
    string str2 = argv[2];
    cout << "Checking if " << str1 << " & " << str2 << " are permuation of each others." << endl;
    using_hash(str1, str2);
    using_sort(str1, str2);
    return 0;
}

