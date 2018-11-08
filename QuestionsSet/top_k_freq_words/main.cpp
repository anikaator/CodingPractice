bool compFunc(pair<string,int>& left, pair<string,int>& right) {
    if(left.second > right.second) {
        return true;
    } else if (left.second < right.second) {
        return false;
    } else {
        int len = (left.first.length() > right.first.length())?(right.first.length()):(left.first.length());
        int i = 0;
        while(i < len) {
            if(left.first[i] > right.first[i]){
                return false;
            } else if (left.first[i] < right.first[i]){
                return true;
            } else {
                i++;
            }
        }
        if (left.first.length() > right.first.length()) {
            return false;
        }
    }


    return true; 
}
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> countMap;
        for(auto &x : words) {
            if(countMap.find(x) == countMap.end()) {
                countMap[x] = 1;
            } else {
                ++countMap[x];
            }
        }
        vector<pair<string, int>> tmp_vec;
        for(auto &x: countMap) {
            tmp_vec.push_back(x);                
        }
        sort(tmp_vec.begin(), tmp_vec.end(), compFunc);
        /*
        for(auto &x: tmp_vec) {
            cout << endl << x.first << ":" << x.second;
        }
        */
        vector<string> ret;
        for(int i = 0; i < k; i++){
            ret.push_back(tmp_vec[i].first);
            //cout << tmp_vec[i].first;
        }
        return ret;    
    }
};


/*
class Solution {
public:
      struct Comp {
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& w : words)
            ++cnt[w];
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> Q;
        for (auto it : cnt)
            Q.emplace(it.second, it.first);
        
        vector<string> res;
        while (k-- > 0 && !Q.empty()) {
            res.push_back(Q.top().second);
            Q.pop();
        }
        
        return res;
    }
};
*/
