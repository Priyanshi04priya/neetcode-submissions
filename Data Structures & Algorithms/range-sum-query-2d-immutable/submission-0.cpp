class NumMatrix {
    vector<vector<int>> pre;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        pre.resize(n, vector<int>(m,0));
        //rowwise column
        for(int i=0;i<n;i++){
            pre[i][0]=mat[i][0];
            for(int j=1;j<m;j++){
                pre[i][j]+=pre[i][j-1]+mat[i][j];
            }
        }
        //column wise prefix
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                pre[i][j]+=pre[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=pre[row2][col2];
        if(row1>0)ans-=pre[row1-1][col2];
        if(col1>0)ans-=pre[row2][col1-1];
        if(row1>0 && col1>0) ans+=pre[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */