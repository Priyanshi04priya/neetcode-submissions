class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    
    int findparent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findparent(parent[u]);
    }

    void unions(int u, int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv)return ;
        if(size[pu]<=size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                pq.push({dist,{i,j}});
            }
        }
        int ans=0;
        DSU dsu(n);
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            int d=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(dsu.findparent(u)!=dsu.findparent(v)){
                dsu.unions(u,v);
                ans+=d;
            }
        }
        return ans;
    }
};
