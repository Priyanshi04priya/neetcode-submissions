class Solution {
public:
    typedef pair<int,int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& it:times){
            int u=it[0];
            int v=it[1];
            int t=it[2];
            adj[u].push_back({v,t});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<p,vector<p>, greater<p>> pq;
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [d,node]=pq.top(); pq.pop();
            if(d>dist[node])continue;
            for(auto& [v,t]:adj[node]){
                if(d+t<dist[v]){
                    dist[v]=d+t;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<n+1;i++){
            maxi=max(maxi,dist[i]);
        }
        return (maxi==1e9)?-1:maxi;
    }
};
