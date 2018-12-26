class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> repeated;
        for(const auto& x : A) {
            if (repeated.find(x) != repeated.end()) {
                return x;
            }
            repeated.emplace(x, 1);
        }
    }
};
