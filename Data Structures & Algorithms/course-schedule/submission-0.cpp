class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
       //adj list
       vector<vector<int>> adj(n);
       for(auto it:pre){
          int u=it[0];
          int v=it[1];
          adj[v].push_back(u);
       } 
       //indegree array
       vector<int> ind(n);
       for(int i=0;i<n;i++){
          for(auto it:adj[i]){
            ind[it]++;
          }
       }
       queue<int> q;
       for(int i=0;i<n;i++){
        if(ind[i]==0)q.push(i);
       }
       int cnt=0;
       while(!q.empty()){
         int temp=q.front(); q.pop();
         cnt++;
         for(auto it:adj[temp]){
            ind[it]--;
            if(ind[it]==0)q.push(it);
         }
       }
       return cnt==n;
    }
};
