class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector<int> prev(n,0) , cur(n,0);
        
        for(int j=0 ; j<n ; j++)
            prev[j] = mat[0][j];
        
        for(int i=1 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                int up = mat[i][j] + prev[j];
                
                int ld = mat[i][j];
                if(j-1 >= 0) ld += prev[j-1];
                else ld += 1e7;
                
                int rd = mat[i][j];
                if(j+1 < n) rd += prev[j+1];
                else rd += 1e7;
                
                
                cur[j] = min(up,min(ld,rd));
            }
            prev = cur;
        }
        
        
        int mini = INT_MAX;
        for(int j=0 ; j<n ; j++)
            mini = min(mini , prev[j]);
        
        return mini;
        
    }
};