class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        int size = A.size();
        unordered_map<int, int> mapAB;
        for(int a = 0; a < size; a++) {
            for(int b = 0; b < size; b++) {
                int sum = A[a] + B[b];
                if(mapAB.find(sum) != mapAB.end()) {
                    mapAB[sum]++;
                } else {
                    mapAB.emplace(sum, 1);
                }
            }
        }

        for(int c = 0; c < size; c++) {
            for(int d = 0; d < size; d++) {
                int sum = (C[c] + D[d]) * -1;
                if(mapAB.find(sum) != mapAB.end()) {
                    count = count + mapAB[sum];
                }
            }
        }
        return count;
    }
};
