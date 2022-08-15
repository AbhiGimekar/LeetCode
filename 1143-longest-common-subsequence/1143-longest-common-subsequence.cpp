class Solution {
public:
    
    int fun(int i , int j , string s1 , string s2 , vector<vector<int>> &dp)
    {
        if(i == 0 || j == 0) return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1 + fun(i-1 , j-1 , s1 , s2 ,dp);
        
        return dp[i][j] =  max(fun(i-1 , j , s1 , s2 , dp) , fun(i , j-1 , s1 , s2 ,dp));
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        vector<int> prev(m+1 ,0) , cur(m+1 ,0);
    
        for(int i=0 ; i<m; i++) prev[i] = 0;
        
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m ; j++)
            {
                if(s1[i-1] == s2[j-1])
                    cur[j] = 1 + prev[j-1];
                else
                    cur[j] =  max(prev[j] , cur[j-1]);       
            }
            prev = cur;
        }
        
        return prev[m];
    }
};