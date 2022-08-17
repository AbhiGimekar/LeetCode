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
        vector<double>  prev(m+1 , 0) ;
        
        prev[0] = 1;
                
        for(int i=1 ; i<=n ; i++)
        {
            for(int  j=m ; j>=1 ; j--)
            {
                if(s1[i-1] == s2[j-1])
                    prev[j] = prev[j-1] + prev[j];
                else
                    prev[j] = prev[j];
            }
        }
        
        
        return (int)prev[m];
    }
};