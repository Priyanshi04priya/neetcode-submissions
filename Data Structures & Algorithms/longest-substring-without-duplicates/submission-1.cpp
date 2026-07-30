class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        vector<int> vis(256,-1);
        int maxi=0;
        while(j<n){
            if(vis[s[j]]>=i){
                i=vis[s[j]]+1;
            }
            vis[s[j]]=j;
            maxi=max(j-i+1,maxi);
            j++;
        }
        return maxi;
    }
};
