class Solution {
public:
    int f(int index, vector<int>& cost,vector<int>& dp){
        if(index>=cost.size())return 0;
        if(dp[index]!=-1)return dp[index];
        return dp[index]=min(f(index+2,cost,dp), f(index+1,cost,dp))+cost[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(f(0,cost,dp), f(1,cost,dp));
    }
};
