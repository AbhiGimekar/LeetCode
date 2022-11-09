//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet
{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);

        if (ultimateParent_u == ultimateParent_v)
            return;
        else if (rank[ultimateParent_u] < rank[ultimateParent_v])
            parent[ultimateParent_u] = ultimateParent_v;
        else if (rank[ultimateParent_v] < rank[ultimateParent_u])
            parent[ultimateParent_v] = ultimateParent_u;
        else
        {
            parent[ultimateParent_u] = ultimateParent_v;
            rank[ultimateParent_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);

        if (ultimateParent_u == ultimateParent_v)
            return;
        else if (size[ultimateParent_u] < size[ultimateParent_v])
        {
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];
        }
        else
        {
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow = 0 , maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        
        for(auto i : stones){
            int nodeRow = i[0];
            int nodeCol = i[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        int cnt = 0;
        for(auto i : stoneNodes){
            if(ds.findParent(i.first) == i.first)
                cnt++;
        }
        
        return n - cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x; cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj,n) << "\n";
    }
}
// } Driver Code Ends