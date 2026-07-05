class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        //inc-1 , dec=0
        bool inc=(arr[0]<arr[1]);
        int n=arr.size();
        if(n==1) return 1;
        
        int cnt=(arr[0] == arr[1])?1:2;
        int maxi=cnt;
        for(int i=1;i<n-1;i++){
            if (arr[i] == arr[i + 1]) {
                cnt = 1;
            }
            else if((arr[i]<arr[i+1] && !inc) || (arr[i]>arr[i+1] && inc)){
                inc = !inc;
                cnt++;
            }
            else {
                inc=(arr[i]<arr[i+1]);
                cnt=2;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};