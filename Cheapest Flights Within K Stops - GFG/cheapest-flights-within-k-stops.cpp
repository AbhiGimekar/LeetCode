//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto i : flights){
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        queue<pair<int, pair<int,int>>> q; // {stops, {node, cost}};
        q.push({0, {src, 0}});
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stops > K) continue;
            for(auto i:adj[node]){
                int adjNode = i.first;
                int wt = i.second;
                
                if(cost + wt < dist[adjNode] && stops <= K){
                    dist[adjNode] = cost + wt;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends