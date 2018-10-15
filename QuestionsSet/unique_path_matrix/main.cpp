#Using recursion

class Solution {
public:
    int uniquePaths(int m, int n) {
        return findPath(0, 0, m, n, 0);
    }
    int findPath(int i, int j, int m, int n, int cnt) { 
        if ((i == (n-1)) && (j == (m-1))) {
            return 1;
        }
        int leftcnt = 0, rightcnt = 0;
        if(j+1 < m) {          
            leftcnt = findPath(i, j+1, m, n, cnt);
        }
        if(i+1 < n) {            
            rightcnt = findPath(i+1, j, m, n, cnt);
        }                 
        return leftcnt+rightcnt;
    }
};
