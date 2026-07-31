class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), m=t.size();
        if(n<m)return "";
        unordered_map<char,int> mpp;
        for(auto &it:t)mpp[it]++;

        //instead of storing thr string we will keep count of start index and length of the string
        int minlen=INT_MAX, start=-1, taken=0;
        int i=0, j=0;
        while(j<n){
            if(mpp[s[j]]>0)taken++;
            mpp[s[j]]--;
            while(taken==m){
                if(j-i+1<minlen){
                    minlen=j-i+1;
                    start=i;
                }
                //shrink the window to phle freq restore then check for the validity of window then i++; 
                mpp[s[i]]++; 
                if(mpp[s[i]]>0)taken--; 
                //valid window nhi, i tabhi update hoga jb ek valid window aaye
                i++;
            }
            j++;
        }
        return (start==-1)?"":s.substr(start, minlen);
    }
};
