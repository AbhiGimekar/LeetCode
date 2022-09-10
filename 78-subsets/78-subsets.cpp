class Solution {
public:
    vector<vector<int>> ans;
    
    void fun(int ind , int n , vector<int> &temp , vector<int> &nums)
    {
        if(ind == n)
        {
            ans.push_back(temp);
            return ;
        }
        
        temp.push_back(nums[ind]);
        fun(ind+1 , n , temp , nums);
        
        temp.pop_back();
        fun(ind+1 , n , temp , nums);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>  temp;
        fun(0 , n , temp , nums);
        
        return ans;
        
    }
};