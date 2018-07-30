class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        struct pair{
            bool col[10];
            bool row[10];
            pair():col{false},row{false} {};
        } ;
        
        struct pair arr[10];
        struct sub_def{
            bool sub[3][3] = {false};            
        };
        struct sub_def sub_arr[10];
        for(int i = 0; i < board.size() ; i++) {
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != '.') {
                    if (arr[board[i][j] - '0'].col[i] == false &&  arr[board[i][j] - '0'].row[j] == false) {
                        arr[board[i][j] - '0'].col[i] = true;
                        arr[board[i][j] - '0'].row[j] = true;
                    } else {
                        return false;
                    }
                    if (sub_arr[board[i][j] - '0'].sub[(int)(i/3)][(int)(j/3)] == false)
                        sub_arr[board[i][j] - '0'].sub[(int)(i/3)][(int)(j/3)] = true;
                    else
                        return false;
                        
                }
                    
            }
        }
        return true;
    }
};
