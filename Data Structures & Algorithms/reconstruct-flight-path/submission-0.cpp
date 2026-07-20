class Solution {
public:
    void dfs(string s,unordered_map<string, deque<string>>& adj, vector<string>& ans){
        auto& vec=adj[s];
        while(!vec.empty()){
            string small_neigh=vec.back();
            vec.pop_back();
            dfs(small_neigh,adj,ans);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;
        for(auto& it:tickets){
            adj[it[0]].push_back({it[1]});
        }
        for(auto& [src,dest]:adj){
            sort(dest.rbegin(), dest.rend());
        }

        vector<string> ans;
        dfs("JFK",adj,ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
