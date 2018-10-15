class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.size();
        int lenb = b.size();
        lena--; lenb--;
        string finalStr("");
        int carry = 0;
        while (lena >= 0 && lenb >= 0) {
            if (a[lena] == '0' && b[lenb] == '0') {
                if (carry == 0) {
                    finalStr = '0' + finalStr;
                    carry = 0;
                } else {
                    finalStr = '1' + finalStr;
                    carry = 0;
                }                    
                carry = 0;                
            } else if ((a[lena] == '0' && b[lenb] == '1') || (a[lena] == '1' && b[lenb] == '0')){
                if (carry == 0) {
                    finalStr = '1' + finalStr;
                    carry = 0;
                } else {
                    finalStr = '0' + finalStr;
                    carry = 1;
                }                                                    
            } else if (a[lena] == '1' && b[lenb] == '1') {
                if (carry == 0) {
                    finalStr = '0' + finalStr;
                    carry = 1;
                } else {
                    finalStr = '1' + finalStr;
                    carry = 1;
                }                                                    
            }
            lena--; lenb--;
        }
        
        
        while (lena >= 0) {
            if (a[lena] == '0') {
                if (carry == 0) {
                    finalStr = '0' + finalStr;
                    carry = 0;
                } else {
                    finalStr = '1' + finalStr;                    
                    carry = 0;
                }
            } else {
                if (carry == 0) {
                    finalStr = '1' + finalStr;
                    carry = 0;
                } else {
                    finalStr = '0' + finalStr;
                    carry = 1;
                }                
            }
            lena--;
        }

        
        while (lenb >= 0) {
            if (b[lenb] == '0') {
                if (carry == 0) {
                    finalStr = '0' + finalStr;
                    carry = 0;
                } else {
                    finalStr = '1' + finalStr;                    
                    carry = 0;
                }
            } else {
                if (carry == 0) {
                    finalStr = '1' + finalStr;
                    carry = 0;
                } else {
                    finalStr = '0' + finalStr;
                    carry = 1;
                }                
            }
            lenb--;
        }

        if (carry == 1)
            finalStr = '1' + finalStr;
        return finalStr;
    }
};
