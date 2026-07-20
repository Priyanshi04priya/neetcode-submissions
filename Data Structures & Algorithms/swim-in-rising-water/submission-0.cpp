class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int swimInWater(vector<vector<int>>& grid) {
       int n=grid.size();
       set<pair<int,int>> vis;
       int dr[]={-1,0,1,0};
       int dc[]={0,1,0,-1};
       priority_queue<p, vector<p>, greater<p>> pq;
       pq.push({grid[0][0],{0,0}});
       vis.insert({0, 0});

       while(!pq.empty()){
           auto it=pq.top(); pq.pop();
           int t=it.first;
           int r=it.second.first;
           int c=it.second.second;
           if(r==n-1 && c==n-1)return t;
           for(int i=0;i<4;i++){
             int nr=r+dr[i];
             int nc=c+dc[i];
             if(nr>=0 && nr<n && nc>=0 && nc<n && !vis.count({nr,nc})){
                vis.insert({nr,nc});
                pq.push({max(t,grid[nr][nc]), {nr,nc}});
             }
           }
       } 
       return n*n;  
    }
};
