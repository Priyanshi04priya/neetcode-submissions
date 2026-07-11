class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        int n=ht.size();
        int m=ht[0].size();
        vector<vector<int>> apurv(n,vector<int>(m,0));
        vector<vector<int>> priya(n,vector<int>(m,0));

        queue<pair<int,int>> qp, qa;
        for(int j=0;j<m;j++){
            priya[0][j]=1;
            qp.push({0, j});
        }
        for(int i=1;i<n;i++){
            priya[i][0]=1;
            qp.push({i,0});
        }
        for(int j=0;j<m;j++){
            apurv[n-1][j]=1;
            qa.push({n-1, j});
        }
        for(int i=0;i<n-1;i++){
            apurv[i][m-1]=1;
            qa.push({i,m-1});
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!qp.empty()){
            auto [r,c]=qp.front(); qp.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !priya[nr][nc] && ht[nr][nc]>=ht[r][c]){
                    priya[nr][nc]=1;
                    qp.push({nr,nc});
                }
            }
        }

        while(!qa.empty()){
            auto [r,c]=qa.front(); qa.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !apurv[nr][nc] && ht[nr][nc]>=ht[r][c]){
                    apurv[nr][nc]=1;
                    qa.push({nr,nc});
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(priya[i][j] && apurv[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
