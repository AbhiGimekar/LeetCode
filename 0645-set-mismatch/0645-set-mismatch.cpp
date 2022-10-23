class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int dup = -1, missing = 1;
        vector<int> mp(nums.size()+1,0);
        
        for(auto i:nums)mp[i]++;
        
        for(int i=0 ; i<=nums.size(); i++)
        {
            if(mp[i] == 0)
                missing = i;
            else if(mp[i] == 2)
                dup = i;
        }
        
        return {dup,missing};
        
                
    }
};