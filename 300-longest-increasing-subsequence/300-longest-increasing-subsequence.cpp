class Solution {
public:
    
    int fun(int index , int prev , vector<int> &nums , vector<vector<int>> &dp)
    {
        if(index == nums.size()+1) return 0;
        
        if(dp[index][prev] != -1)return dp[index][prev]; 
        
        int notTake = 0 + fun(index+1 , prev , nums ,dp);
        int take = -1e9;
        if(prev == 0 || nums[index-1] > nums[prev-1])
            take = 1 + fun(index+1 , index , nums ,dp);
        
        return dp[index][prev] = max(take , notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>>  dp(n+1 , vector<int>(n ,-1));
        
        return fun(1 , 0 , nums ,dp);
        
        
    }
};