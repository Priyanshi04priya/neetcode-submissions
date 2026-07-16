class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    void dfs(int node, int src, vector<int>& vis, unordered_set<pair<int,int>,hash_pair>& st, vector<vector<int>>& adj){
        vis[node]=true;
        for(auto it:adj[node]){
            st.insert({src,it});
            if(!vis[it]){
                dfs(it,src,vis,st,adj);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qr) {
        unordered_set<pair<int,int>, hash_pair> st;
        vector<vector<int>> adj(n);
        for(auto it:pre){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            dfs(i,i,vis,st,adj);
        }
        vector<bool> ans;
        for(auto it:qr){
            ans.push_back(st.count({it[0], it[1]}));
        }
        return ans;
    }
};