class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map <int, int> dup_map;
        vector <int> final_vec;
        for (auto &x : nums1) {
            std::pair<std::map<int,int>::iterator,bool> ret;
            ret = dup_map.insert(std::pair<int,int>(x, 1));
            if (ret.second == false) {
                dup_map[x] = ++dup_map[x];
            }                         
        }
        for (auto &x : nums2) {
            auto it = dup_map.find(x);
            if (it != dup_map.end()) {
                final_vec.emplace_back(x);
                if(it->second == 1) {
                    dup_map.erase(it);                    
                } else {
                    dup_map[x] = dup_map[x] - 1;
                }                                  
            }                            
        }
        return final_vec;
    }
};
