class Solution {
public:
    bool valid(string s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1])return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int low=0, high=s.size()-1;
        while(low<high){
            if(s[low]!=s[high]){
                return valid(s.substr(0,low)+s.substr(low+1, s.size()-low-1)) || valid(s.substr(0, high)+s.substr(high+1));
            }
            low++;
            high--;
        }
        return true;
    }
};