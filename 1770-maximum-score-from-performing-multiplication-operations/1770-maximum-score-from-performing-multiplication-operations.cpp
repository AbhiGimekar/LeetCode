class Solution {
public:
    
    int fun(int left , vector<int>  &nums , vector<int> &multipliers , int j ,          vector<vector<int>> &dp)
    {
        int n = nums.size();
        if(j == multipliers.size())
            return 0;
        
        if(dp[j][left] != -1)return dp[j][left];
        
        int leftMul = (nums[left]*multipliers[j]) +  fun(left+1 , nums , multipliers , j+1 , dp);
        
        int rightMul = (nums[(n-1) - (j-left)]*multipliers[j]) + fun(left , nums , multipliers , j+1 ,dp) ;
        
        return dp[j][left] = max(leftMul , rightMul);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size(); 
        int m = multipliers.size();
        
        vector<vector<int>> dp(m+1 , vector<int>(m+1 , 0));
        vector<int> after(m+1 , 0) , cur(m+1 , 0);
        
        for(int j = m-1 ; j>=0 ; j--)
        {
            for(int left = j ; left>=0 ; left--)
            {
                int leftMul = (nums[left]*multipliers[j]) +  after[left+1];
        
                int rightMul = (nums[(n-1) - (j-left)]*multipliers[j]) + after[left] ;
        
                cur[left] = max(leftMul , rightMul);
            }
            after = cur;
        }
        
        return after[0];
    }
};