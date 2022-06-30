class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        sort(begin(nums) , end(nums));
        
        int i=0 , j=n-1;
        
        int ans=0;
        while(i<j)
        {
            ans += (nums[j]-nums[i]);
            i++;
            j--;
        }
        
        return ans;
    }
};