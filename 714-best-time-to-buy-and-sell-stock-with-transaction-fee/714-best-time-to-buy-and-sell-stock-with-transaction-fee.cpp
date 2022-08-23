class Solution {
public:
    
    int fun(int  index , int buy , int fee , int n , vector<int> &prices ,vector<vector<int>> &dp)
    {
        if(index == n) return 0;
        
        if(dp[index][buy] != -1)return dp[index][buy];
        
        if(buy)
        {
            return dp[index][buy] = max(-prices[index] +  fun(index+1 , 0 , fee , n , prices ,dp),
                                0     + fun(index+1 , 1 , fee , n, prices ,dp));
        }
        else
        {
            return dp[index][buy] = max(prices[index] - fee + fun(index+1 , 1 , fee , n , prices ,dp) ,
                                0     + fun(index+1 , 0 , fee , n , prices ,dp)) ;
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(2,0));
        
        for(int index = n-1 ; index >= 0 ; index--)
        {
            dp[index][1] = max(-prices[index] + dp[index+1][0] , 0 + dp[index+1][1]);
            dp[index][0] = max(prices[index]-fee + dp[index+1][1] , 0 + dp[index+1][0]);
        }
        
        return dp[0][1];
    }
};