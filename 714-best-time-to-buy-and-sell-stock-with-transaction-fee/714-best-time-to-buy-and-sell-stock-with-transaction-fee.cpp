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
        
        vector<vector<int>> dp(n , vector<int>(2,-1));
        
        return fun(0 , 1 , fee , n , prices  ,dp);
    }
};