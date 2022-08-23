class Solution {
public:
    
    int fun(int index , int buy , int n , vector<int> &prices , vector<vector<int>> &dp)
    {
        
        if(index >= n )return 0;
        
        if(dp[index][buy] != -1) return dp[index][buy] ;
        
        if(buy)
        {
            return dp[index][buy] = max(-prices[index] + fun(index+1 , 0 , n , prices ,dp) ,
                                0     + fun(index+1 , 1 , n , prices,dp));
        }
        else
        {
            return dp[index][buy] = max(prices[index] + fun(index+2 , 1 , n , prices,dp),
                              0      + fun(index+1 , 0 , n , prices ,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+2 , vector<int> (2,0));
        
        for(int  index = n-1 ; index >= 0 ; index--)
        {
            for(int buy = 0 ; buy <= 1; buy++)
            {
                if(buy)
                {
                    dp[index][buy] = max(-prices[index] + dp[index+1][0] , 0 + dp[index+1][1]);
                }
                else
                {
                    dp[index][buy] = max(prices[index] + dp[index+2][1] , 0 + dp[index+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};