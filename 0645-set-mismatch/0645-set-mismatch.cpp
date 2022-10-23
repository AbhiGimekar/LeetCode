class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        sort(begin(nums),end(nums));
        int dup = -1 , missing = 1;
        
        for(int i=1 ; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                dup = nums[i];
            else if(nums[i] > nums[i-1] + 1)
                missing = nums[i-1] + 1;
        }
        
        int n = nums.size();
        missing = nums[n-1] != n ? n : missing;
        
        return {dup,missing};
                
    }
};