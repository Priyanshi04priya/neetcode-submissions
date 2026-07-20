class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n=nums.size();
        if(nums.empty()) return 0;
        int maxi=1;
        for(int it:st){
            //can this be our ist number
            if(!st.count(it-1)){
                int cnt=1;
                while(st.count(it+1)){
                    cnt++;
                    it++;
                }
                maxi=max(cnt,maxi);
            }
        }
        return maxi;
    }
};
