class Solution {
public:
    int fun(int n , int m , vector<vector<int>> &mat ,vector<vector<int>> &dp)
    {
        if(n>=0 && m>=0 && mat[n][m] == 1)return 0;
        if(n==0 && m==0)return  1;
        if(n<0 || m<0)return 0;
    
        if(dp[n][m] != -1)return dp[n][m];
    
        int left = fun(n , m-1 , mat ,dp);
        int up = fun(n-1,m,mat ,dp);
    
        return dp[n][m] = (left + up);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m , -1));
        
        return fun(n-1,m-1,mat ,dp );
    }
};