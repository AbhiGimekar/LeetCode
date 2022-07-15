class Solution {
public:
    
    int dfs(int i , int j , vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(i>=m || j>=n || i<0 || j<0 || grid[i][j] != 1)return 0;
        grid[i][j] = 'v';
        
        int up = dfs(i-1 , j , grid);
        int down = dfs(i+1 , j , grid);
        int left = dfs(i , j-1 , grid);
        int right = dfs(i , j+1 , grid);
        
        return (up + down + left + right + 1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int  area = 0;
        for(int i=0 ; i<grid.size() ; ++i)
        {
            for(int  j=0 ; j<grid[0].size() ; ++j)
            {
                if(grid[i][j] == 1)area = max(area , dfs(i , j , grid));
            }
        }
        
        return area;
    }
};