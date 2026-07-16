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

    void unionS(int u,int v){
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
    int countComponents(int n, vector<vector<int>>& edges) {
        dsu d(n);
        int cnt=0;
        for (auto &e:edges) {
            d.unionS(e[0], e[1]);
        }
        for(int i=0;i<n;i++){
            if(d.findparent(i)==i)cnt++;
        }
        return cnt;
    }
};
