class Solution {
public:
    
    void fun(int ind , int n , vector<int> &temp , vector<vector<int>> &ans ,  vector<int> &nums)
    {
        ans.push_back(temp);
        for(int i = ind ; i < n ; i++)
        {
            if(i != ind && nums[i] == nums[i-1])continue;
            temp.push_back(nums[i]);
            fun(i+1 , n , temp , ans, nums);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(begin(nums),end(nums));
        
        fun(0 , n , temp ,ans ,  nums);
        
        return ans;
        
    }
};