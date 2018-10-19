class Solution {
public:
    int MIN = -9999;
    string minWindow(string s, string t) {
        map<char, set <int>> data;
        for (auto &x : t) {
            auto it = data.find(x);
            if (it == data.end()) {
                set<int> tmp_set;
                tmp_set.insert(MIN);
                data.emplace(x,tmp_set);
            }
        }
        int i =0;
        for (auto &x : s) {
            auto it = data.find(x);
            if (it != data.end()) {
                it->second.insert(i);            
            }            
            i++;
        }
        set<int>::iterator minPtr, maxPtr;
        bool first = false;
        map<char, set<int>::iterator> marker;
        for (auto &x : data) {
            if (*(x.second.begin()) == MIN)
                x.second.erase(x.second.begin());
            marker.emplace(x.first, x.second.begin());
            if (!first) {
                maxPtr = minPtr = x.second.begin();
                first = true;
                continue;
            }
            if(*(x.second.begin()) < *minPtr) {
                minPtr = x.second.begin();
            }
            if(*(x.second.begin()) > *maxPtr) {
                maxPtr = x.second.begin();
            }
        }
        int minDist = *maxPtr - *minPtr;
        cout << *minPtr << ":" << *maxPtr << " dist : " << minDist;
        bool allend = false;
        set<int>::iterator newMaxPtr = maxPtr;
        while (!allend) {
            maxPtr = newMaxPtr;
            allend = true;
            while (auto &x : marker) {
                if(x.second != x.second.end())
                    allend = false; continue;
                if (*(x.second + 1) > *maxPtr && (newMaxPtr + 1 ) > (x.second + 1))
                    newMaxPtr = x.second;
            }
            ++newMaxPtr;
            
        }
        
        return "";
    }
};
