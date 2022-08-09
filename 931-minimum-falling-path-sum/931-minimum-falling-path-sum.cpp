class Solution {
public:
    
    int fun(int i , int j , int n , vector<vector<int>> &mat , vector<vector<int>> &dp)
    {   
        if(j<0 || j>=n)return 1e7;
        if(i == 0)return dp[i][j] =  mat[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = mat[i][j] + fun(i-1 , j , n , mat ,dp);
        int ld = mat[i][j] + fun(i-1, j-1 , n ,mat ,dp);
        int rd = mat[i][j] + fun(i-1 , j+1 , n, mat ,dp);
        
        return dp[i][j] =  min(up , min(ld,rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector<vector<int>> dp(n , vector<int>(n,0));
        
        for(int j=0 ; j<n ; j++)
            dp[0][j] = mat[0][j];
        
        for(int i=1 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                int up = mat[i][j] + dp[i-1][j];
                
                int ld = mat[i][j];
                if(j-1 >= 0) ld += dp[i-1][j-1];
                else ld += 1e7;
                
                int rd = mat[i][j];
                if(j+1 < n) rd += dp[i-1][j+1];
                else rd += 1e7;
                
                
                dp[i][j] = min(up,min(ld,rd));
            }
        }
        
        
        int mini = INT_MAX;
        for(int j=0 ; j<n ; j++)
            mini = min(mini , dp[n-1][j]);
        
        return mini;
        
    }
};