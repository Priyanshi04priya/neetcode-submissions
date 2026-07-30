class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=INT_MAX;
        int profit=0;
        int n=prices.size();
        int curr=INT_MIN;
        for(int i=0;i<n;i++){
            cost=min(prices[i], cost);
            curr=prices[i]-cost;
            profit=max(profit, curr);
        }
        return profit;
    }
};
