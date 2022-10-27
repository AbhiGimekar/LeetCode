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
        int vis[V] , pathVis[V], check[V];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            pathVis[i] = 0;
            check[i] = 0;
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis, check);
            }
        }
        
        vector<int> safeNodes;
        for(int i=0; i<V; i++){
            if(check[i])
                safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};