class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int cnt = 0;
        bool last_blank = true;
        while (len) {
            if (s[len -1] == ' ' && last_blank) {
                len--;
                continue;   
            }                
            if (isalpha(s[len-1])) {            
                len--; cnt++;
                last_blank = false;
                continue;
            }                
            break;                
        }
        return cnt;
    }
};
