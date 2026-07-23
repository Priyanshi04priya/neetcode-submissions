// class Solution {
// public:
//     void qs(vector<int>& nums, int lt, int rt){
//         if(lt>=rt)return;
//         int pivot=nums[rt];
//         int i=lt;
//         for(int j=lt;j<rt;j++){
//             if(nums[j]<pivot){
//                 swap(nums[i],nums[j]);
//                 i++;
//             }
//         }
//         swap(nums[i], nums[rt]);
//         qs(nums,lt,i-1);
//         qs(nums,i+1,rt);
//     }
//     vector<int> sortArray(vector<int>& nums) {
//         qs(nums,0,nums.size()-1);
//         return nums;
//     }
// };

class Solution {
public:
    void merge(vector<int>& nums, int lt, int m, int rt){
        int i=lt, j=m+1;
        vector<int> temp;
        while(i<=m && j<=rt){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=rt){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=lt;i<=rt;i++){
            nums[i]=temp[i-lt];
        }
    }
    void partition(vector<int>& nums, int lt, int rt){
        if(lt>=rt)return;
        int mid=lt+(rt-lt)/2;
        partition(nums, lt, mid);
        partition(nums, mid+1, rt);
        merge(nums,lt,mid,rt);
    }
    vector<int> sortArray(vector<int>& nums) {
        partition(nums,0,nums.size()-1);
        return nums;
    }
};