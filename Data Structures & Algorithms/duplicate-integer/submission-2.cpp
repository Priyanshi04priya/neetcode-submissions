class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        return !(st.size()==nums.size());

        // int sum=accumulate(nums.begin(),nums.end(),0);
        // int n=nums.size();
        // int r_sum=n*(n+1)/2;
        // return !(r_sum==sum);   //values  can be negative also so it will not work

    }
};