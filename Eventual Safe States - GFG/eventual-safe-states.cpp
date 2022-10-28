//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto i: adj[node]){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis, check) == true){
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
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> adjRev[V];
        int inDegree[V] = {0};
        
        for(int i=0; i<V; i++){
            // i --> j 
            for(auto j:adj[i]){
                adjRev[j].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++)
            if(inDegree[i] == 0)
                q.push(i);
        
        
        vector<int> safeNodes;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(auto i:adjRev[node]){
                inDegree[i]--;
                if(inDegree[i] == 0) q.push(i);
            }
        }
        
        sort(begin(safeNodes), end(safeNodes));
        return safeNodes;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends