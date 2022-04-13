class Solution {
public:
    void backTrack(int n , int k , int start , vector<vector<int>> & ans, vector<int> & comb)
    {
        if(comb.size() == k){
            ans.push_back(comb);
            return ;
        }
        
        for(int i=start ; i<=n ; i++ ){
            comb.push_back(i);
            backTrack(n , k , i+1 , ans , comb);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        backTrack(n , k , 1 , ans , comb);
        
        return ans;
    }
};