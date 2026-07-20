class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //at max two elements ho sakte hai
        int n=nums.size();
        int ele1=0, ele2=0, cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0){
                ele1=nums[i];
                cnt1=1;
            }
            else if(nums[i]!=ele1 && cnt2==0){
                ele2=nums[i];
                cnt2=1;
            }
            else if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else{
                cnt1--, cnt2--;
            }
        }
        int count1=0, count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1)count1++;
            else if(nums[i]==ele2)count2++;
        }
        vector<int> ans;
        if(count1>n/3)ans.push_back(ele1);
        if(count2>n/3)ans.push_back(ele2);
        return ans;
    }
};