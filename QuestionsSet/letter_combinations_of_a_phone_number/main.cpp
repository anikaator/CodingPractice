#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string digits = "237";
	vector<string> code = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> final_list;
	for (auto &x : digits) {
		if (x < '2' && x > '9')
			continue;
		vector<string> tmp_list;
		if (final_list.size() == 0) {
			for (auto &ch : code[x - '2']) {
				final_list.emplace_back(string(1,ch));
			}
			continue;
		}
		for (auto &elem :  final_list) {
			for (auto &ch : code[x - '2']) {
				tmp_list.emplace_back(elem + ch);
			}
		}
		final_list = tmp_list;
	}
	for (auto &x : final_list) cout << endl << x;
    return 0;
}
