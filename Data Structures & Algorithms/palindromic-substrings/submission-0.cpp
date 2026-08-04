class Solution {
public:
    int f(int i,int j,string& s){
        int cnt=0;
        int n=s.size();
        while(i>=0 && j<n && s[i]==s[j]){
            cnt++, i--, j++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=f(i,i,s);
            ans+=f(i,i+1,s);
        }
        return ans;
    }
};
