class Solution {
public:    
    int compress(vector<char>& chars) {
        int idx = 0;
        char mark = NULL;
        int cnt = 1;
        for(auto& ch : chars) {
            if(ch != mark) {                 
                if (cnt > 1) {
                    if (cnt / 100 > 0){
                        chars[idx++] = (cnt/100) + '0';    
                    }
                    cnt = cnt%100;
                    if (cnt / 10 > 0){
                        chars[idx++] = (cnt/10) + '0';    
                    }
                    cnt = cnt%10;
                    chars[idx++] = (cnt) + '0';                        
                }                
                chars[idx++] = ch;                
                mark = ch;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if (cnt > 1) {
            if (cnt / 100 > 0){
                chars[idx++] = (cnt/100) + '0';    
            }
            cnt = cnt%100;
            if (cnt / 10 > 0){
                chars[idx++] = (cnt/10) + '0';    
            }
            cnt = cnt%10;
            chars[idx++] = (cnt) + '0';  
        }
        chars[idx] = NULL;
        return idx;
    }
};
