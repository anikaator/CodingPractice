class Solution {
public:
    bool validPalindrome(string s) {
        int l = s.length();
        int i=0;
        while (i < l/2) {
            if(s[i] != s[l-i-1]) {
                return checkPalin(s,i, l-i-1);
            } else {
                i++;
            }
        }        
        return true;
    }
    
    bool checkPalin(string &s, int i, int j) {
        return checkRev(s, i+1, j) || checkRev(s, i, j-1);
    }
    
    bool checkRev(string &s, int i, int j) {
        for(int c = 0; c <= (j-i)/2; c++) {
            if(s[i+c] != s[j-c])
                return false;
        }
        return true;
    }
        
};
