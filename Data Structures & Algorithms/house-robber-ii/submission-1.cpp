// class Solution {
// public:
//     int f(int i,vector<int>& nums,vector<int>& dp){
//         if(i<0)return 0;
//         if(dp[i]!=-1)return dp[i];
//         int ntake=f(i-1,nums,dp);
//         int take=nums[i]+f(i-2,nums,dp);
//         return dp[i]=max(ntake,take);
//     }
//     int ft(vector<int>& nums){
//         int n=nums.size();
//         if(n==0)return 0;
//         if(n==1)return nums[0];
//         vector<int> dp(n,0);
//         dp[0]=nums[0];
//         dp[1]=max(nums[0],nums[1]);
//         for(int i=2;i<n;i++){
//             dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
//         }
//         return dp[n-1];
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1)return nums[0];
//         vector<int> temp1(n),temp2(n);
//         for(int i=0;i<n-1;i++)temp1[i]=nums[i];
//         for(int i=1;i<n;i++)temp2[i]=nums[i];
//         return max(ft(temp1),ft(temp2));
//     }
// };
class Solution {
public:
    int rob1(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        int prev1=max(nums[0], nums[1]);
        int prev2=nums[0];
        for(int i=2;i<n;i++){
            int curr=max(prev1, nums[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        //exclude last element
        for(int i=0;i<n-1;i++){
            temp1.push_back(nums[i]);
        }
        //exclude first element
        for(int i=1;i<n;i++){
            temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};
