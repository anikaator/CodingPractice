class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> cnt_map;
        string word;
        stringstream ss(A);
        while (ss >> word) {
            auto it = cnt_map.find(word);
            if (it == cnt_map.end()) {
                cnt_map.emplace(word,1);                
            } else {
                it->second++;
            }
        }
        stringstream sb(B);
        while (sb >> word) {
            auto it = cnt_map.find(word);
            if (it == cnt_map.end()) {
                cnt_map.emplace(word,1);                
            } else {
                it->second++;
            }
        }
        vector<string> result;
        for (auto &x : cnt_map) {
            if(x.second == 1)
                result.push_back(x.first);
        }
        return result;
    }
};
