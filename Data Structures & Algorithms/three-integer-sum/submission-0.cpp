class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n=nums.size();
    
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;  //avoid duplicates
            int sum=-nums[i];
            int j=i+1, k=n-1;
            while(j<k){
                int tsum=nums[j]+nums[k];
                if(tsum==sum){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;
                    while (j<k && nums[j]==nums[j-1])j++;
                    while (j<k && nums[k] == nums[k+1]) k--;
                }
                else if(tsum<sum){
                    j++;
                }
                else k--;
            }
        }
        return res;
    }
};
