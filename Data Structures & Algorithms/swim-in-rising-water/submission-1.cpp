class Solution {
public:
    typedef pair<int,pair<int,int>> p;

    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        priority_queue<p,vector<p>,greater<p>> pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int t=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(t>dist[r][c])continue;
            if(r==n-1 && c==n-1)return t;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int newtime=max(t,grid[nr][nc]);
                    if(newtime<dist[nr][nc]){
                        dist[nr][nc]=newtime;
                        pq.push({newtime,{nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};