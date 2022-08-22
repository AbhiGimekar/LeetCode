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
        
        vector<int>  after(5,0) , cur(5,0);
        
        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int transactionNo = 0 ; transactionNo < 4 ; transactionNo++)
            {
                if(transactionNo % 2 == 0)
                    cur[transactionNo] = max(-prices[index] + after[transactionNo+1] ,
                                                         0        + after[transactionNo]);
                else
                    cur[transactionNo] = max(prices[index] + after[transactionNo+1] ,
                                                         0       + after[transactionNo]);
            }
            after = cur;
        }
        
        return after[0];
    }
};