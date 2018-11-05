class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int i=0;
        int len = paragraph.length();
        if (len == 0){
            return "";
        }            
        while(!isalpha(paragraph[i]) && i < len) {
            i++;            
        }
        if(i == len) {
            return "";
        }
        map<string, bool> banhash;
        for(auto &x : banned) {
            transform(x.begin(), x.end(), x.begin(), ::tolower); 
            banhash.emplace(x, true);
        }
        map<string, int> countmap;

        while(i < len) {            
            while(!isalpha(paragraph[i]) && i < len) {
                i++;            
            }
            int start = i;
            while((isalpha(paragraph[i])) && i < len) {
                i++;            
            }
            string check = paragraph.substr(start, i-start);
            if(check.length() <= 0)
            continue;
            transform(check.begin(), check.end(), check.begin(), ::tolower); 
            if (banhash.find(check) != banhash.end()) {
                continue;
            }
            if (countmap.find(check) != countmap.end()) {
                ++countmap[check];
            } else {
                countmap.emplace(check, 1);
            }
        }      
        int max = 0;
        string ret = "";      
        for (auto &x : countmap) {
            //cout << endl << x.first << ":" << x.second;
            if (x.second > max){
                max = x.second;
                ret = x.first;    
            }                
        }
        return ret; 
    }
};



/*
Better solution:

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string res = "";
        unordered_map<string, int> count;
        for (auto& c: paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        istringstream iss(paragraph);
        string word;
        while (iss >> word) {
            count[word]++;
        }
        for (auto& w: banned) {
            count[w] = 0;
        }
        int mx = 0;
        for (auto& w: count) {
            if (w.second > mx) {
                res = w.first;
                mx = w.second;
            }
        }
        return res;
    }
};
*/
