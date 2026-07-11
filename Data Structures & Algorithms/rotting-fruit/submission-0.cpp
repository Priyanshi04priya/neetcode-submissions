class Solution {
public:
    typedef pair<pair<int,int>,int> p;
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<p> q;
        int fresh = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int ans=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front(); q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int t=it.second;
            ans=max(ans,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    fresh--;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        if (fresh>0)return -1;
        return ans;
    }
};
