class Solution {
public:
    
    void markAdj(vector<vector<char>>& grid, int r, int c, int row, int col) {
        if (r >= 0 && r < row && c >= 0 && c < col && grid[r][c] == '1') {
            grid[r][c] = 'a';        
            markAdj(grid, r-1,c, row, col);
            markAdj(grid, r,c-1, row, col);
            markAdj(grid, r+1,c, row, col);
            markAdj(grid, r,c+1, row, col);            
        }
    }
    void printIsland(vector<vector<char>>& grid, int r, int c, int row, int col) {
        for (int r = 0; r < row; r++){
            cout <<endl;
            for (int c=0; c < col; c++) {
                cout << grid[r][c];
            }
        }
        cout << endl << "============";
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();
        int total_island = 0;
        for (int r = 0; r < row; r++){
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == '1') {                    
                    ++total_island;
                    markAdj(grid, r,c, row, col);
                    //printIsland(grid, r,c, row, col);
                }
            }
        }                
        return total_island; 
    }
};
