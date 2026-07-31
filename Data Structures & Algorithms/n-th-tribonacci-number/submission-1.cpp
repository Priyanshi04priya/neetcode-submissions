// class Solution {
// public:
//     int tribonacci(int n) {
//         if(n<=1)return n;
//         if(n==2)return 1;
//         return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
//     }
// };

// class Solution {
// public:
//     int tribonacci(int n) {
//         if(n<=1)return n;
//         if(n==2)return 1;
//         vector<int> dp(n+1);
//         dp[0]=0, dp[1]=1, dp[2]=1;
//         for(int i=3;i<=n;i++){
//             dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int tribonacci(int n) {
        if(n<=1)return n;
        if(n==2)return 1;
        int prev1=0, prev2=1, prev3=1;
        for(int i=3;i<=n;i++){
            int curr = prev1+prev2+prev3;
            prev1=prev2;
            prev2=prev3;
            prev3=curr;
        }
        return prev3;
    }
};