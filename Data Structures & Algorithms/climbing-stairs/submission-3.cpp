// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==1 || n==2)return n;
//         return climbStairs(n-1)+climbStairs(n-2);
//     }
// };

// class Solution {
// public:
//     //Tabulation
//     int climbStairs(int n) {
//         if(n<=2)return n;
//         vector<int> dp(n+1);
//         dp[1]=1, dp[2]=2;
//         for(int i=3;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    //space optimization
    int climbStairs(int n) {
        if(n<=2)return n;
        int prev1=1, prev2=2;
        for(int i=3;i<=n;i++){
            int curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};