class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        
        vector<vector<int>> after(2 , vector<int>(3 , 0));
        vector<vector<int>> cur(2 , vector<int>(3 , 0));

        
        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                for(int rem = 1 ; rem <= 2 ; rem++)
                {
                    if(buy)
                    {
                        cur[buy][rem] = max(-prices[index] + after[0][rem] ,
                                                           0     + after[1][rem]);
                    }
                    else
                    {
                        cur[buy][rem] = max(prices[index] + after[1][rem-1] ,
                                                            0   + after[0][rem]);
                    }
                }
            }
            after = cur;
        }
        
        
        
        return after[1][2];
    }
};