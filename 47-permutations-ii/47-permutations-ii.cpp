class Solution {
public:
    
    void RecurPermu(vector<int> &ds , vector<int> &nums ,  set<vector<int>> &ans , int freq[])
    {
        if(ds.size() == nums.size()){
            ans.insert(ds);
            return ;
        }
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1 ;
                RecurPermu(ds , nums , ans , freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        
        for(int i=0 ; i<nums.size() ; i++) freq[i]=0;
        
        RecurPermu(ds , nums , ans , freq);
        
        
        vector<vector<int>> res;
        
        for(auto i:ans)
        {   
            vector<int> temp;
            for(auto j:i)
                temp.push_back(j);
            res.push_back(temp);
        }
        
        return res;
        
    }
};