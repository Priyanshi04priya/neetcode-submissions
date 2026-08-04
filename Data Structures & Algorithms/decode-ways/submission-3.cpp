// class Solution {
// public:
//     int f(int i,string s,vector<int>& dp){
//         int n=s.size();
//         if(i<0)return 1;
//         if(i==0)return s[0]!='0';
        
//         if(dp[i]!=-1)return dp[i];
//         int take1=0, take2=0;

//         int r=s[i]-'0';
//         if(r>=1 && r<=9)take1=f(i-1,s,dp);

//         r=(s[i-1]-'0')*10 + (s[i]-'0');
//         if(r>=10 && r<=26)take2=f(i-2,s,dp);

//         return dp[i]=take1+take2;
//     }
//     int numDecodings(string s) {
//         int n=s.size();
//         vector<int> dp(n,-1);
//         return f(n-1,s,dp);
//     }
// };

class Solution {
    int f(int i,string &s,vector<int>&dp)
    {
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;
        if(i==s.size()-1) return 1;
        if(dp[i]!=-1) return dp[i];

        int w=f(i+1,s,dp);
        if(s[i]<'2' || (s[i]=='2' && s[i+1]<='6'))
        {
            w+=f(i+2,s,dp);
        }
        return dp[i]=w;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return f(0,s,dp);
    }
};