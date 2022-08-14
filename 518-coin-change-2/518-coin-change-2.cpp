class Solution {
public:
    int fun(int index , int target , vector<int> &coins , vector<vector<int>> &dp)
    {
        if(index == 0)
        {    
            if(target%coins[0] == 0) return 1;
            else return 0;
        }
        
        if(dp[index][target] != -1) return dp[index][target];
        
        int notTake = 0 + fun(index-1 , target , coins ,dp);
        int take = 0;
        if(coins[index] <= target) take =  fun(index , target-coins[index] , coins ,dp);
        
        return dp[index][target] = notTake + take;
    }
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , 0));
        
        for(int target = 0 ; target <= amount ; target++)
            if(target%coins[0] == 0)dp[0][target] = 1;
        
        for(int  index = 1 ; index < n  ; index++)
        {
            for(int target=0 ; target <= amount ; target++)
            {
                int notTake = 0 + dp[index-1][target];
                int take = 0;
                if(coins[index] <= target) take =  dp[index][target-coins[index]];

                dp[index][target] = notTake + take;
            }
        }
        
        return dp[n-1][amount];
    }
};