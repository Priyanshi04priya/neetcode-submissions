class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n=nums.size();
       for(int i=0;i<n;i++){
          int idx=abs(nums[i]);
          if(nums[idx]>0)nums[idx]=-nums[idx];
          else return idx;
       }
       return -1;
    }
};
