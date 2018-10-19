class Solution {
public:
    string reverseOnlyLetters(string S) {
        int startPtr = 0;
        int endPtr = S.length() - 1;
        while (startPtr < endPtr) {
            if (!isalpha(S[startPtr])) {
                startPtr++; 
                continue;
            }
            if (!isalpha(S[endPtr])) {
                endPtr--; 
                continue;
            }
            swap(S[startPtr], S[endPtr]);
            startPtr++;
            endPtr--;
        }
        return S;
    }
};
