// class Solution {
// public:
//     int f(int index, vector<int>& cost,vector<int>& dp){
//         if(index>=cost.size())return 0;
//         if(dp[index]!=-1)return dp[index];
//         return dp[index]=min(f(index+2,cost,dp), f(index+1,cost,dp))+cost[index];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         vector<int> dp(cost.size(),-1);
//         return min(f(0,cost,dp), f(1,cost,dp));
//     }
// };


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2);
        for(int i=cost.size()-1;i>=0;i--){
            dp[i]=min(dp[i+2],dp[i+1])+cost[i];
        }
        return min(dp[0], dp[1]);
    }
};
