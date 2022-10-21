class Solution {
    void dfs(int node , vector<int> adjList[] , int vis[])
    {
        vis[node] = 1;
        for(auto i:adjList[node])
        {
            if(!vis[i])
                dfs(i , adjList , vis);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> adjList[n+1];
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(isConnected[i][j] == 1 &&  i != j)
                {
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
        }
        
        int vis[n+1];
        for(int i=0 ; i<=n ; i++)vis[i] = 0;
        
        int cnt=0;
        
        for(int i = 1 ; i<= n ; i++)
        {
            if(!vis[i]){
                cnt++;
                dfs(i , adjList , vis);
            }
        }
        
        return cnt;
    }
};