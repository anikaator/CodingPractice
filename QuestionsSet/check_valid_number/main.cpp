class Solution {
public:
    bool isNumber(string s) {
        bool sign = false;
        bool exp = false;
        bool deci = false;
        int i = 0;
        while (i < s.length()) {
            if( s[i] == 'e'){
                if (i == 0 || exp == true)
                    return false;                
                exp = true;
            }
            if( s[i] == '.') {
                if (deci == true || exp == true || i == 0) {
                    return false;                  
                }                    
                deci = true;
            }
            if( s[i] == '+' ||  s[i] == '-') {
                if (sign == true) {
                    return false;
                }                    
                sign = true;
            }
            if (isalpha(s[i]) && (s[i] != 'e')) {
                return false;
            }                
            i++;
        }
        return true;
    }
};
