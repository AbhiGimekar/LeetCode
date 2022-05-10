class Solution {
public:
    vector<vector<int>> ans;
    
    void findCombination(int ind , int target , vector<int>&arr , vector<int>&ds)
    {
        if(ind == arr.size()){
            if(target == 0)
                ans.push_back(ds);
            return ;
        }
        
        //Pick Up The Element
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind , target-arr[ind] , arr , ds);
            ds.pop_back();
        }
        
        findCombination(ind+1 , target , arr , ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> ds;
        findCombination(0 , target , candidates , ds);
        return ans;
        
    }
};