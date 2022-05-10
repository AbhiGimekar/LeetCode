class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(candidates.begin() , candidates.end());
        
        combinations(0 , target , candidates  , temp , ans);
        return ans;
    }
    
    void combinations(const int ind, const int target,vector<int> &candidates, vector<int> &temp ,                                                         vector<vector<int>> &ans)
    {
        if(target < 0)
            return;
        if(target == 0)
        {
            //cout<<"HI ";
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=ind ; i<candidates.size() ; i++)
        {   
            
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            combinations(i + 1 , target-candidates[i] , candidates , temp , ans);
            temp.pop_back();
        }
    }
};