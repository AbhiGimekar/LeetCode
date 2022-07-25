class Solution {
public:
    int lower_bound(vector<int>& nums , int target)
    {
        int low = 0 , high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = lower_bound(nums, target);
        int  last = lower_bound(nums, target+1)-1;
        
        if(first < nums.size() && nums[first] == target)
            return {first , last};
        else 
            return {-1 ,-1};
    }
};