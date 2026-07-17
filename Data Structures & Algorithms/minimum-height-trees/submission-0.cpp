class Solution {
public:
    int bfs(int root, vector<vector<int>>& adj){
        int n=adj.size();
        vector<int> vis(n);
        int mini=-1;
        queue<int> q;
        q.push(root);
        vis[root]=1;

        while(!q.empty()){
            int siz=q.size();
            mini++;

            while(siz--){
                int node=q.front(); q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
        return mini;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({bfs(i,adj),i});
        }
        int node=pq.top().second;
        int mini=pq.top().first;
        pq.pop();
        ans.push_back(node);

        while(!pq.empty() && pq.top().first==mini){
            auto it=pq.top(); pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};