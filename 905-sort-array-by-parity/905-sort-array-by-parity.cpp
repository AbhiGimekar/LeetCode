class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        vector<int> ans;
        
        int i,n=nums.size();
        
        for(i=0;i<n;i++){
            if(nums[i]%2) ans.emplace_back(nums[i]);
            else ans.insert(ans.begin() , nums[i]);
        }
        
         return ans;
    }
};