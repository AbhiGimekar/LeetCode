class Solution {
    bool check(int start, int V, vector<vector<int>> &adj, int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i:adj[node]){
                if(color[i] == -1){
                    color[i] = !color[node];
                    q.push(i);
                }
                else if(color[i] == color[node])
                    return false;
            }
        }
        return true;  
    }
    
    bool dfs(int node, int col, vector<vector<int>> &graph, int color[])
    {
        color[node] = col;
        
        for(auto i:graph[node]){
            if(color[i] == -1){
                if(dfs(i, !col, graph, color) == false)
                    return false;
            }
            else if(color[i] == color[node])
                return false;
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();
        
        int color[V];
        for(int i=0; i<V; i++)color[i] = -1;
        
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                // if(check(i, V, graph, color) == false)
                //     return false;
                if(dfs(i, 0, graph, color) == false)
                    return false;
            }
        }
        return true;
        
    }
};