class Solution {
public:
    
    int fun(int  i , int j , vector<int>  &cuts , vector<vector<int>> &dp)
    {
        if(i > j) return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int mini = 1e9;
        for(int ind = i ; ind <= j ; ind++)
        {
            int cost = cuts[j+1]-cuts[i-1] + fun(i , ind-1,cuts , dp) + fun(ind+1 , j,cuts , dp);
            mini = min(mini,cost);
        }
        
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(cuts.begin() , cuts.end());
        
        int c = cuts.size();
        
        vector<vector<int>> dp(c+1 , vector<int>(c+1,-1));
        
        return fun(1 , c-2  , cuts , dp);
    }
};