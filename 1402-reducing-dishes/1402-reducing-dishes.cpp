class Solution {
public:
    
    int fun(int index , int no , int n , vector<int> &satisfaction , vector<vector<int>> &dp)
    {
        
        if(index == n)
            return 0;
        
        if(dp[index][no] != -1) return dp[index][no];
        
        int notTake = 0 + fun(index+1 , no , n , satisfaction ,dp);
        int take = no*satisfaction[index] + fun(index+1 , no+1 , n , satisfaction ,dp);
        
        return dp[index][no] = max(notTake , take);
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        sort(satisfaction.begin() , satisfaction.end());
        
        vector<vector<int>> dp(n+1 , vector<int>(n+2,0));
        
        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int no = 1 ; no <= n ; no++)
            {
                int notTake = 0 + dp[index+1][no];
                int take = no*satisfaction[index] + dp[index+1][no+1];

                dp[index][no] = max(notTake , take);
            }
        }
        
        return dp[0][1];
        
    }
};