class Solution {
public:
    int f(int i,vector<int>& coins, int amt){
        if(i<0)return 1e9;
        if(i==0){
            if(amt%coins[0]==0) return amt/coins[0];
            return 1e9;
        }
        int take=1e9, ntake=1e9;
        ntake=f(i-1,coins,amt);
        if(amt>=coins[i])take=1+f(i,coins,amt-coins[i]);
        return min(ntake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans= f(coins.size()-1, coins,amount);
        return (ans>=1e9)?-1:ans;
    }
};
