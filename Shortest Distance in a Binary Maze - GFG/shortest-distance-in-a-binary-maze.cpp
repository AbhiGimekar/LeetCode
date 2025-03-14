//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        if(source.first == destination.first && source.second == destination.second)
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> pq; // {distance, {row, col} }
        pq.push({0,{source.first, source.second}});
        
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!pq.empty()){
            int dis = pq.front().first;
            int row = pq.front().second.first;
            int col = pq.front().second.second;
            pq.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1)
                {
                    if(dis + 1 < dist[nrow][ncol])
                    {
                        pq.push({dis+1, {nrow, ncol}});
                        dist[nrow][ncol] = dis + 1;
                        
                        if(nrow == destination.first && ncol == destination.second)
                            return dis + 1;
                    }
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends