class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //we will store index to have a check of out of bound condition 
        //remove all elements at index less than equal to (i-k)
        //deque me start me max rakhenge agar next element greater hai to phle wale min ko pop karate jao
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()<=i-k)dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i])dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
