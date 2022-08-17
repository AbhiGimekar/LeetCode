class Solution {
public:
    
    int fun(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp)
    {
        if(j == 0)return 1;
        if(i == 0)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        if(s1[i-1] == s2[j-1])
            return dp[i][j] = fun(i-1,j-1,s1,s2,dp) + fun(i-1,j,s1,s2,dp);
        else
            return dp[i][j] = fun(i-1,j,s1,s2,dp);
    }
    
    int numDistinct(string s1, string s2) {
        
        int n = s1.size() ;
        int m = s2.size() ;
        vector<vector<int>>  dp(n+1 , vector<int>(m+1,-1));
    
        return fun(n , m , s1 , s2 ,dp);
    }
};