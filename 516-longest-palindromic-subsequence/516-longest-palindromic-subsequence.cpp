class Solution {
public:
    int fun(int i , int j , string s1 , string s2 , vector<vector<int>> &dp)
    {
        if(i == 0 || j == 0) return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + fun(i-1 , j-1 , s1 , s2 , dp);
        
        return dp[i][j] = max(fun(i-1 , j , s1 ,s2 , dp) , fun(i , j-1 , s1 ,s2 , dp));
        
    }
    int longestPalindromeSubseq(string s1) {
        
        int n = s1.size();
        
        string s2 = "";
        for(int i=n-1 ; i>=0 ; i--)
            s2 += s1[i];
        
        vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));
        
        for(int j=0 ; j<=n ; j++) dp[0][j] = 0;
        for(int i=0 ; i<=n ; i++) dp[i][0] = 0;
        
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=n ; j++)
            {
                if(s1[i-1] == s2[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }
};