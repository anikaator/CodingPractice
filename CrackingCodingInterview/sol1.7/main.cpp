class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        /*
        for(int a = 0; a<n;a++){
            for (int b=0;b<n;b++){
                cout << matrix[a][b];
            }
            cout<< endl;
        }
        */
        for(int i = 0; i < n/2; ++i) {
            for(int j = i; j < (n-1-i); ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[(n-1) - j][i];
                matrix[(n-1) - j][i] = matrix[(n-1) - i][(n-1) - j];
                matrix[(n-1) - i][(n-1) - j] = matrix[j][(n-1) - i];
                matrix[j][(n-1) - i] = tmp;            
            }
            /*
            cout << "\nNew one:\n";
            for(int a = 0; a<n;a++){
                for (int b=0;b<n;b++){
                    cout << matrix[a][b];
                }
                cout<< endl;
            }
            */
        }
    }
};
