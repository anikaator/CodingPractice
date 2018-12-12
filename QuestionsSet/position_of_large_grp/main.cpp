class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int len = s.length();
        if(len <= 1) {
            return result;
        }
        int start = 0;
        int i;
        for (i = 1; i < len; i++) {
            if(s[i] != s[start]) {
                if((i - start) >= 3) {
                    vector<int> pair;
                    pair.push_back(start);
                    pair.push_back(i-1);
                    result.push_back(pair);                    
                }
                start = i;
            }
        }
        if(((i - start) >= 3) && (i != start)) {
            vector<int> pair;
            pair.push_back(start);
            pair.push_back(i-1);
            result.push_back(pair);                    
        }

        return result;
    }
};
