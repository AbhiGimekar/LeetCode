class Solution {
public:
    
    int fun(int index , int transactionNo , int n , int k , vector<int> &prices , vector<vector<int>> &dp)
    {
        if(index == n || transactionNo == 2*k)return 0;
        
        if(dp[index][transactionNo] != -1) return dp[index][transactionNo];
        
        if(transactionNo % 2 == 0)
        {
            return dp[index][transactionNo] = max(-prices[index] + fun(index+1 , transactionNo+1 , n , k , prices,dp) ,
                             0        + fun(index+1 , transactionNo , n , k , prices,dp));
        }
        else
        {
            return dp[index][transactionNo] = max(prices[index] + fun(index+1 , transactionNo+1 , n , k , prices,dp),
                             0       + fun(index+1 , transactionNo , n , k , prices,dp));
        }
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(2*k+1 , 0));
        
        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int transactionNo = 2*k-1 ; transactionNo >= 0 ; transactionNo--)
            {
                if(transactionNo % 2 == 0)
                {
                    dp[index][transactionNo] = max(-prices[index] + dp[index+1][transactionNo+1] ,
                                     0        + dp[index+1][transactionNo]);
                }
                else
                {
                    dp[index][transactionNo] = max(prices[index] + dp[index+1][transactionNo+1],
                                     0       + dp[index+1][transactionNo]);
                }
            }
        }
        
        return dp[0][0];
    }
};