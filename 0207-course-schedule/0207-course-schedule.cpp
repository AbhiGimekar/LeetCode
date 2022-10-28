class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[V];
        for(auto i:prerequisites)
            adj[i[1]].push_back(i[0]);
        
        vector<int> inDegree(V,0);
        for(int i=0; i<V ; i++)
        {
            for(auto j:adj[i])
                inDegree[j]++;
        }
        
        queue<int> q;
        for(int i=0; i<V; i++)
            if(inDegree[i] == 0)
                q.push(i);
        
        vector<int>  topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto i:adj[node]){
                inDegree[i]--;
                if(inDegree[i] == 0)
                    q.push(i);
            }
        }
        
        if(topo.size() == V) return true;
        return false;
    }
};