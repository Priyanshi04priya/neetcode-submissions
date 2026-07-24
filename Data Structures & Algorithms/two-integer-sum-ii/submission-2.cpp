// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n=numbers.size();
//         unordered_map<int,int> mpp;
//         for(int i=0;i<n;i++){
//             int num=target-numbers[i];
//             if(mpp.count(num))return {mpp[num]+1, i+1};
//             mpp[numbers[i]]=i;
//         }
//         return {-1,-1};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            int sum=numbers[i]+numbers[j];
            if(sum==target)return {i+1,j+1};
            else if(sum>target){
                j--;
            }
            else i++;
        }
    }
};
