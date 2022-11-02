class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
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