class Solution {
    int mod = 1e9+7;
public:
    
    int fun(int n ,int k , int target, vector<vector<long long>> &dp)
    {
        // if(target < 0)return 0;
        if(n == 0 || target < 0)
        {
            return target == 0 ? 1 : 0;
        }
        
        if(dp[n][target] != -1)return dp[n][target];
        
        int ans = 0;
        for(int ind = 1 ; ind<=k ; ind++){
            ans += fun(n-1 , k , target- ind , dp);
            ans %= mod;
        }
        return dp[n][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<long long >> dp(n+1 , vector<long long>(target+1 , -1));
        return fun(n , k , target , dp);
    }
};