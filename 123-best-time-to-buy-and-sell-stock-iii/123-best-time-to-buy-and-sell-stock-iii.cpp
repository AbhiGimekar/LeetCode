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
        
        
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)));
        
        return fun(0 , 1 , 2 , n , prices , dp);
    }
};