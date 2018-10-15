class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if (s.length() == 0)
            return true;
        
        int f = 0;
        int r = len -1;
        while (f < r) {
            if(!((s[f] >= 'A' && s[f] <= 'Z') || (s[f] >= 'a' && s[f] <= 'z') || (s[f] >= '0' && s[f] <= '9'))) {
                f++;
                continue;
            }
            if(!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9'))) {
                r--;
                continue;
            }
            if (tolower(s[f]) == tolower(s[r])) {
                f++; r--; 
                continue;
            } else {
                return false;
            }
        }
        return true;        
    }
};
