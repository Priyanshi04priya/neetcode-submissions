class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //our concern is only for the numbers [1,n] agr bde honge ya negative ya 0 then it can't be our answer we need smallest positive integer
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n)nums[i]=n+1;
        }

        for(int i=0;i<n;i++){
            int val=abs(nums[i]);
            if(val>=1 && val<=n){
                nums[val-1]=-abs(nums[val-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }
};