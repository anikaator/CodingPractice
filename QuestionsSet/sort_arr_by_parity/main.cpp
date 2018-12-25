class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len = A.size();        
        int cnt = 0;
        while(cnt < len) {
            if ((cnt % 2 == 0 && A[cnt] % 2 == 0) || (cnt % 2 == 1 && A[cnt] % 2 == 1)) {
                cnt++;
                continue;
            }
            int mark = cnt + 1;
            while ((cnt % 2 == 0 && A[mark] % 2 != 0) || (cnt % 2 == 1 && A[mark] % 2 != 1)) {
                mark++;
            }
            swap(A[cnt], A[mark]);
            cnt++;
        }
        return A;
    }
};

/* Better solution
vector<int> sortArrayByParityII(vector<int>& A) {
    for (int i = 0, j = 1; i < A.size(); i += 2, j += 2) {
        while (i < A.size() && A[i] % 2 == 0) i += 2;
        while (j < A.size() && A[j] % 2 == 1) j += 2;
        if (i < A.size()) swap(A[i], A[j]);
    }
    return A;
}
*/
