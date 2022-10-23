class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int dup = -1, missing = 1;
        unordered_map<int,int> mp;
        for(auto i:nums)mp[i]++;
        
        for(int i=0 ; i<=nums.size(); i++)
        {
            if(mp.find(i) != mp.end())
            {
                if(mp[i] == 2)
                    dup = i;
            }
            else
            {
                missing = i;
            }
        }
        
        return {dup,missing};
        
                
    }
};