class Solution {
public:
    
    int fun(int index , int prev , vector<int> &nums , vector<vector<int>> &dp)
    {
        if(index == nums.size()) return 0;
        
        if(dp[index][prev+1] != -1) return dp[index][prev+1];
        
        int notTake = 0 + fun(index+ 1, prev , nums ,dp);
        int take = 0;
        if(prev == -1 || nums[index] > nums[prev])
            take = 1 + fun(index+1 , index , nums , dp);
        
        return dp[index][prev+1] = max(take , notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
        
        for(int index = n-1 ; index >= 0 ; index--)
        {
            for(int prev = index-1 ; prev >= -1 ; prev--)
            {
                int notTake = 0 + dp[index+1][prev+1];
                int take = 0;
                if(prev == -1 || nums[index] > nums[prev])
                    take = 1 + dp[index+1][index+1];

                dp[index][prev+1] = max(take , notTake);
            }
        }
        
        return dp[0][0];
    }
};