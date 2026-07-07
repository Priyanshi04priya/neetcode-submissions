class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr=0;
        for(int it:nums){
            xr^=it;
        }
        return xr;
    }
};
