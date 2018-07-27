class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lenLS = 0;
        int ch_map[255];
        for (auto &x : ch_map) x = -1;
        int sPtr=0;
        int dPtr=0;
        for (auto &ch : s) {
            if (ch_map[ch] != -1) {
                    if (sPtr < (ch_map[ch] + 1))
                        sPtr = ch_map[ch] + 1;
            }
            if (((dPtr - sPtr)+1) > lenLS) 
                lenLS = (dPtr - sPtr) + 1;                
            ch_map[ch] = dPtr;
            //cout << s[sPtr] << ":" << s[dPtr] << "-" << lenLS << endl;
            dPtr++;
        }
        dPtr--;
        if ((dPtr - sPtr) > lenLS) lenLS = (dPtr - sPtr);
        if (lenLS == 0) lenLS = s.size();
        return lenLS;
    }
};
