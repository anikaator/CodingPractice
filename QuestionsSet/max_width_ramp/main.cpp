class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int max_ramp = -1;
        int len = A.size();
        for (int i = 0; i < len ; i++) {
            int j = len - 1;
            if (j-i <= max_ramp)
                break;
            while(i < j) {
                if (j-i <= max_ramp)
                    break;
                if (A[i] <= A[j]) {
                    max_ramp = max(max_ramp, j-i);
                }
                j--;
            }
        }
        return ((max_ramp > 0)?max_ramp:0);
    }
};
