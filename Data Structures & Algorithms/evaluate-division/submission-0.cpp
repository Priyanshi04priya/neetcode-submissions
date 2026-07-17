class Solution {
public:
    typedef pair<string,double> p;
    double dfs(string src, string target, unordered_map<string, vector<p>>& adj, unordered_set<string>& vis){
        if(!adj.count(src) || !adj.count(target))return -1.0;
        if(src==target)return 1.0;
        vis.insert(src);
        for(auto& it:adj[src]){
            string v=it.first;
            double w=it.second;
            if(!vis.count(v)){
                double res=dfs(v,target,adj,vis);
                if(res!=-1.0)return w*res;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<p>> adj;
        for(int i=0;i<values.size();i++){
            string u=eq[i][0];
            string v=eq[i][1];
            adj[u].emplace_back(v,values[i]);
            adj[v].emplace_back(u,1.0/values[i]);
        }

        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            unordered_set<string> vis;
            string src=queries[i][0];
            string target=queries[i][1];
            ans.push_back(dfs(src,target,adj,vis));
        }
        return ans;
    }
};