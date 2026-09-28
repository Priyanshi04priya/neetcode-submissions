class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        //window size k+1, is window size me if there is any duplicate
        int i=0, j=0;
        unordered_map<int,int> mpp;
        while(j<n){
            if(j-i>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0)mpp.erase(nums[i]);
                i++;
            }
            if(mpp.count(nums[j]))return true;
            mpp[nums[j]]++;
            j++;
        }
        return false;
    }
};