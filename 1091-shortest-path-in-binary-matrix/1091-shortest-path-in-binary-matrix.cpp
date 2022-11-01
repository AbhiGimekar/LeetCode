class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1)return -1;
        if(grid.size() == 1) return 1;
        
        int n = grid.size();
        queue<pair<int,pair<int,int>>> q;
        q.push({1, {0,0}}); // {distance, {row, col}}
        
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        dist[0][0] = 0;
        
        while(!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int drow=-1; drow<=1; drow++){
                for(int dcol=-1; dcol<=1; dcol++){
                    int nrow = row + drow;
                    int ncol = col + dcol;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 0)
                    {
                        if(dis + 1 < dist[nrow][ncol])
                        {
                            dist[nrow][ncol] = dis + 1;
                            q.push({dis+1, {nrow,ncol}});
                            
                            if(nrow == n-1 && ncol == n-1)
                                return dis+1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};