class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n=nums.size();
        if(nums.empty()) return 0;
        int maxi=1;
        for(int i=0;i<n;i++){
            //can this be our ist number
            int ele=nums[i];
            if(!st.count(ele-1)){
                int cnt=1;
                while(st.count(ele+1)){
                    cnt++;
                    ele++;
                }
                maxi=max(cnt,maxi);
            }
        }
        return maxi;
    }
};
