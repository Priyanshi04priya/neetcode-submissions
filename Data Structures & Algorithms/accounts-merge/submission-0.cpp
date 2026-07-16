class dsu{
    public:
    vector<int> parent, size;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
      //let the name node is represented by index, to agr email map me phle se aaya hoga to useto dono node ko union  kr denge nhi to new node
      //jin node ko union kiya use merge krna hai
      unordered_map<string,int> mpp;
      int n=acc.size();
      dsu d(n);
      for(int i=0;i<n;i++){
        for(int j=1;j<acc[i].size();j++){
            string email=acc[i][j];
            if(!mpp.count(email))mpp[email]=i;
            else d.unionS(i,mpp[email]);
        }
      }

      vector<vector<string>> ans(n),res;
      for(auto& it:mpp){
        int par=d.findparent(it.second);
        ans[par].push_back(it.first);
      }
      for(int i=0;i<n;i++){
        if(ans[i].empty())continue;
        sort(ans[i].begin(), ans[i].end());
        ans[i].insert(ans[i].begin(),acc[i][0]);
        res.push_back(ans[i]);
      }
      return res;
    }
};