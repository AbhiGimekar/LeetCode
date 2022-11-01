class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans(m,0);
        vector<vector<int>> dp(n+1, vector<int>(m,-1));
        
        for(int row=n; row>=0; row--){
            for(int col=0; col<m; col++){
                if(row == n){
                    dp[row][col] = col;
                    continue;
                }
                
                int nextCol = col + grid[row][col];
                if(nextCol < 0 || nextCol > m-1 || grid[row][col] != grid[row][nextCol])
                    dp[row][col] = -1;
                else
                    dp[row][col] = dp[row+1][nextCol];
                
                if(row == 0)
                    ans[col] = dp[row][col];
            }
        }
        
        return ans;
    }
};