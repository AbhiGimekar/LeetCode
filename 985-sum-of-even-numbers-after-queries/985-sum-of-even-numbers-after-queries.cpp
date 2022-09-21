class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum=0;
        for(auto  &i:nums)
            if(i%2==0)
                sum+=i;
        
        
        vector<int> ans;
        for(auto &i:queries)
        {
            int val = i[0] , index = i[1];
            
            if(nums[index]%2==0) sum -= nums[index];
            nums[index]+=val;
            
            if(nums[index]%2 == 0)sum+=nums[index];
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};