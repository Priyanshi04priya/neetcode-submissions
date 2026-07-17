class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& ht) {
        int n=ht.size();
        int m=ht[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            auto temp=pq.top(); pq.pop();
            int diff=temp.first;
            int r=temp.second.first;
            int c=temp.second.second;
            if(r==n-1 && c==m-1)return diff;
            if(diff>dist[r][c]) continue;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newd=max(diff,abs(ht[nr][nc]-ht[r][c]));
                    if(newd<dist[nr][nc]){
                        pq.push({newd,{nr,nc}});
                        dist[nr][nc]=newd;
                    }
                }
            }
        }
        return 0;
    }
};