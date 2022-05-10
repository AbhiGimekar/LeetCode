class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(1 , k , n , temp , ans);
        return ans;
    }
    
    void combinations(int start , int k , int n , vector<int> &temp , vector<vector<int>> &ans)
    {
        if(k < 0 && n < 0)
            return ;
        if(k == 0 && n == 0)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(int i=start ; i<=9 ; i++)
        {
            temp.push_back(i);
            combinations(i+1 , k-1 , n-i , temp , ans);
            temp.pop_back();
        }
    }
};