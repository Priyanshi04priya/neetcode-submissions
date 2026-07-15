class Solution {
public:
    bool dfs(int start, int parent, vector<vector<int>>& adj, unordered_set<int>& visit){
        if(visit.count(start))return false;
        visit.insert(start);
        for(auto it:adj[start]){
            if(!visit.count(it)){
                if(!dfs(it,start,adj,visit)) return false;
            }
            else if(parent!=it)return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1)return false;
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_set<int> visit;
        if(!dfs(0,-1,adj,visit))return false;
        return visit.size()==n;
    }
};
