class Solution {
    void dfs(int row, int col , int initialColor, int newColor, vector<vector<int>>  &ans,
             vector<vector<int>> &image , int delRow[] , int delCol[])
    {
        ans[row][col] = newColor;
        int n = ans.size();
        int m = ans[0].size();
        
        for(int i=0; i<4 ; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
              image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, initialColor, newColor, ans, image, delRow, delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        int delRow[] = {-1, 0 , +1 , 0};
        int delCol[] = {0, +1 , 0 , -1};
        
        dfs(sr, sc, initialColor , color, ans, image, delRow, delCol);
        
        return ans;
    }
};