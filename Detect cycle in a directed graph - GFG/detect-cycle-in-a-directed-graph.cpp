//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis) == true)
                    return true;
            }
            else if(pathVis[i])
                return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int inDegree[V] = {0};
        for(int i=0; i<V; i++){
            for(auto j:adj[i])
                inDegree[j]++;
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto i:adj[node]){
                inDegree[i]--;
                if(inDegree[i] == 0)
                    q.push(i);
            }
        }
        
        if(cnt == V) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends