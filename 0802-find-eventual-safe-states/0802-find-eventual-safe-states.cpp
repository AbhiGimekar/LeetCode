class Solution {
    bool dfs(int node, vector<vector<int>> &graph, int vis[], int pathVis[], int check[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto i:graph[node])
        {
            if(!vis[i]){
                if(dfs(i, graph, vis, pathVis, check) == true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[i]){
                check[node] = 0;
                return true;
            }
        }
        
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<vector<int>> adj(V);
        vector<int> inDegree(V,0);
        
        for(int i=0; i<V; i++){
            for(auto j:graph[i])
            {
                adj[j].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        vector<int> safeNodes;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(auto i:adj[node])
            {
                inDegree[i]--;
                if(inDegree[i] == 0)
                    q.push(i);
            }
        }
        
        sort(begin(safeNodes), end(safeNodes));
        return safeNodes;
    }
};