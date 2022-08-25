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
        vector<int> dp(n,1);
        
        for(int index = 0 ; index < n  ; index++)
        {
            for(int prev = 0 ; prev < index ; prev++)
            {
                if(nums[prev] < nums[index])
                    dp[index] = max(dp[index] , 1+dp[prev]);
            }
        }
        
        return *max_element(dp.begin() , dp.end());
    }
};