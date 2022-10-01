class Solution {
public:
    int fun(int ind , string s , int n , vector<int> &dp)
    {
        if(ind == n)return 1;
        if(s[ind] == '0')return 0;
        
        if(dp[ind] != -1)return dp[ind];
        
        int ans = fun(ind+1 , s , n , dp);
        if(ind < n-1 && (s[ind] == '1' || (s[ind] == '2' && s[ind+1] < '7')))
            ans += fun(ind+2 , s , n , dp);
        
        return dp[ind] = ans;
        
    }
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(n+1 , -1);
        return fun(0 , s , n , dp);
    }
};