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
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        vector<vector<int>> dp(n , vector<int>(n,-1));
        int mini = INT_MAX;
        for(int j=0 ; j<n ; j++)
            mini = min(mini , fun(n-1,j,n,matrix,dp));
        
        return mini;
        
    }
};