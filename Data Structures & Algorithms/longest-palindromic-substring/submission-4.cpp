class Solution {
public:
    void f(int i, int j, string& s, int& start, int& maxlen){
        int n=s.size();
        while(i>=0 && j<=n-1 && s[i]==s[j]){
            if(j-i+1>maxlen){
                start=i;
                maxlen=j-i+1;
            }
            i--, j++;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0, maxlen=1;
        for(int i=0;i<n;i++){
            f(i,i,s,start,maxlen);
            f(i,i+1,s,start,maxlen);
        }
        return s.substr(start,maxlen);
    }
};
