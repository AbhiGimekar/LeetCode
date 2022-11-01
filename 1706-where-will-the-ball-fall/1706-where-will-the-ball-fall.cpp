class Solution {
public:
    
    int finalBallDropColumn(int row, int col, vector<vector<int>> &grid)
    {
        if(row == grid.size())
            return col;
        
        int nextCol = col + grid[row][col];
        if(nextCol < 0 || nextCol > grid[0].size()-1 || 
            grid[row][col] != grid[row][nextCol])
            return -1;
        
        return finalBallDropColumn(row+1, nextCol, grid);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid[0].size();
        vector<int> ans(n,0);
        
        for(int i=0; i<n ; i++)
            ans[i] = finalBallDropColumn(0, i, grid);
        
        return ans;
    }
};