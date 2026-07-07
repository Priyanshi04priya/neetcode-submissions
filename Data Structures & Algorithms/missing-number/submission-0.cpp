class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr=0;
        int n=nums.size();
        for(int i=0;i<=n;i++){
            xr^=i;
        }
        for(int i=0;i<n;i++){
            xr^=nums[i];
        }
        return xr;
    }
};
