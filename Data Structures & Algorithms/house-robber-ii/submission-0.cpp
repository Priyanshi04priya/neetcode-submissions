class Solution {
public:
    int f(int i,int start,vector<int>& nums,vector<int>& dp){
        int n=nums.size();
        if(i<start)return 0;
        if(i==start)return nums[start];
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]+f(i-2, start, nums, dp);
        int ntake=f(i-1,start,nums, dp);
        return dp[i]=max(take, ntake);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        vector<int> dp1(n,-1), dp2(n,-1);
        int ans1=f(n-1,1,nums,dp1);//include last element
        int ans2=f(n-2,0,nums,dp2);//exclude last element
        return max(ans1, ans2);
    }
};
