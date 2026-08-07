// class Solution {
// public:
//     int f(int i,int j,vector<vector<int>>& dp){
//         if(i<0 || j<0)return 0;
//         if(i==0 && j==0)return 1;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int up=f(i-1,j,dp);
//         int left=f(i,j-1,dp);
//         return dp[i][j]=up+left;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return f(m-1,n-1,dp);
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[1][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if (i==1 && j==1) continue;
                int up=dp[i-1][j];
                int left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m][n];
    }
};
