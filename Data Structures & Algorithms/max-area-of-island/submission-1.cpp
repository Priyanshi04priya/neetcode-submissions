class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        queue<pair<int,int>> q;
        int maxa=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vis[i][j]=1;
                    int area=1;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [r,c]=q.front(); q.pop();
                        for(int i=0;i<4;i++){
                            int nr=r+dr[i];
                            int nc=c+dc[i];
                            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                                area++;
                            }
                        }
                    }
                    maxa=max(maxa,area);
                }
            }
        }
        return maxa;
    }
};
