class Solution {
public:
    
    int fun(int index , int  transactionNo , int n , vector<int> &prices , vector<vector<int>> &dp)
    {
        if(index == n || transactionNo == 4) return 0;
        
        if(dp[index][transactionNo] != -1)return dp[index][transactionNo];
        
        if(transactionNo % 2 == 0) 
        {
            return dp[index][transactionNo] = max(-prices[index] + fun(index+1 , transactionNo+1 , n , prices ,dp) ,
                                0     + fun(index+1 , transactionNo , n , prices,dp));
        }
        else
        { 
            return dp[index][transactionNo] = max(prices[index] + fun(index+1 , transactionNo+1 , n , prices,dp), 
                                 0   + fun(index+1 , transactionNo , n , prices ,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n , vector<int>(4,-1));
        
        return fun(0 , 0 , n , prices ,dp);
    }
};