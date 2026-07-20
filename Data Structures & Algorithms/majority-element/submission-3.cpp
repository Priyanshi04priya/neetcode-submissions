class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                ele=nums[i];
                cnt=1;
            }
            if(nums[i]==ele)cnt++;
            else{
                cnt--;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele)count++;
        }
        return (count>=n/2)?ele:-1;
        //return ele;
    }
};