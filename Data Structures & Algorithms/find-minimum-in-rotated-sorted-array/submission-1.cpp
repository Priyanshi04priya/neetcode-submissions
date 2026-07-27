// class Solution {
// public:
//     int findMin(vector<int> &nums) {
//         //pivot element
//         int ans=INT_MAX;
//         int n=nums.size();
//         int low=0, high=n-1;
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(nums[low]<=nums[high]){
//                 ans=min(ans,nums[low]);
//                 return ans;
//             }
//             else if(nums[mid]>=nums[low]){
//                 ans=min(ans,nums[low]);
//                 low=mid+1;
//             }
//             else {
//                 ans=min(ans,nums[mid]);
//                 high=mid-1;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high])low=mid+1; //mini is in right half
            else high=mid;
        }
        return nums[low];
    }
};