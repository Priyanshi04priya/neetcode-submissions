class dsu{
    public:
    vector<int> parent,size;
    dsu(int n){
        parent.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findparent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findparent(parent[u]);
    }

    void unionS(int u, int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv)return ;
        if(size[pu]<=size[pv]){
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        else{
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu d(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(d.findparent(u)!=d.findparent(v))d.unionS(u,v);
            else return {u,v}; //bcz this contains only one extra edge
        }
        return {};
    }
};





































