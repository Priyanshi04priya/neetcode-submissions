class Solution {
public:
    typedef pair<int,int> p;
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<p> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int cnt=0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j]=1;
                    cnt++;
                    while(!q.empty()){
                        auto [r,c]=q.front(); q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+dr[k];
                            int nc=c+dc[k];
                            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == '1'){
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};
