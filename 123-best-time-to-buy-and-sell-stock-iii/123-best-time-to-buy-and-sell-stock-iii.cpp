class Solution {
public:
    
    int fun(int index , int buy , int rem , int n , vector<int> &prices , vector<vector<vector<int>>> &dp)
    {
        
        if(rem == 0)return 0;
        if(index == n )return 0;
        
        if(dp[index][buy][rem] != -1)return dp[index][buy][rem];
        
        if(buy)
        {
            return dp[index][buy][rem] = max(-prices[index] + fun(index+1 , 0 , rem , n , prices ,dp) ,
                                  0   + fun(index+1 , 1 , rem , n , prices,dp));
        }
        else
        {
            return dp[index][buy][rem] = max(prices[index] + fun(index+1 , 1 , rem-1 , n , prices ,dp), 
                                   0 + fun(index+1 , 0 , rem , n , prices ,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int>(3 , 0)));
        
        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                for(int rem = 1 ; rem <= 2 ; rem++)
                {
                    if(buy)
                    {
                        dp[index][buy][rem] = max(-prices[index] + dp[index+1][0][rem] ,
                                                           0     + dp[index+1][1][rem]);
                    }
                    else
                    {
                        dp[index][buy][rem] = max(prices[index] + dp[index+1][1][rem-1] ,
                                                            0   + dp[index+1][0][rem]);
                    }
                }
            }
        }
        
        
        
        return dp[0][1][2];
    }
};