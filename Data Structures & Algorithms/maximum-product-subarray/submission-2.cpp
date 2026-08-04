// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//        int n=nums.size();
//        long long pre=1; 
//        long long suff=1;
//        long long ans=nums[0];
//        for(int i=0;i<n;i++){
//           if(pre==0)pre=1;
//           if(suff==0)suff=1;
//           pre*=nums[i];
//           suff*=nums[n-i-1];
//           ans=max(ans, max(pre,suff));
//        }
//        return (int)ans;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n=nums.size();
       int maxi=nums[0];
       int mini=nums[0];
       int ans=nums[0];
       for(int i=1;i<n;i++){
          if(nums[i]<0)swap(maxi,mini);
          maxi=max(nums[i],nums[i]*maxi);
          mini=min(nums[i],nums[i]*mini);
          ans=max(ans,maxi);
       }
       return ans;
    }
};
