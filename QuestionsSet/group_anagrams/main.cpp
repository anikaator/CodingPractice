class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> str_map;
        for(auto &str : strs) {
            string sort_str = str;
            sort(sort_str.begin(),sort_str.end());
            str_map[sort_str].push_back(str);
        }
        vector<vector<string>> ret_vec;
        for (auto elem : str_map) {
            ret_vec.push_back(elem.second);
            /*
            //for printing
            cout << endl << elem.first << " :";
            for (auto &str : elem.second) {
                cout << " " << str;
            }
            */
        }
        return ret_vec;
    }
};
