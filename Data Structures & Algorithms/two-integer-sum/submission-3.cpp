class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int s=0,e=n-1;
        while(s<e){
            if((arr[s].first+arr[e].first)==target)return {min(arr[s].second,arr[e].second),max(arr[s].second,arr[e].second)};
            else if((arr[s].first+arr[e].first)<target)s++;
            else e--;
        }
        return {};
    }
};
