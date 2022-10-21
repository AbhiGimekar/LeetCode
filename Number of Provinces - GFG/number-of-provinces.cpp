//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int node , vector<int> adjList[] , int vis[])
    {
        vis[node] = 1;
        for(auto  i:adjList[node])
        {   
            if(!vis[i])
                dfs(i , adjList , vis);
        }
    }
    
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjList[V];
        for(int i=0; i<V ; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int cnt = 0;
        
        for(int v = 0 ; v<V ; v++)
        {
            if(vis[v] == 0)
            {
                cnt++;
                dfs(v , adjList , vis);
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends