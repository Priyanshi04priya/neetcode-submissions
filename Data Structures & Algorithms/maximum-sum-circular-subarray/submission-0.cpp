class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int sum=0;

        int mini=nums[0];
        int sum2=0;
        int t=0;

        for(int i=0;i<n;i++){
            t+=nums[i];
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0)sum=0;

            sum2+=nums[i];
            mini=min(mini, sum2);
            if(sum2>0)sum2=0;
        }
        if(maxi<0)return maxi;
        return max(t-mini, maxi);
    }
};
