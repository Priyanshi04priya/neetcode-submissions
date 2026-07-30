class Solution {
public:
    int characterReplacement(string s, int k) {
        //the question is to make all the characters same by minimum replacement 
        //window-maxf to number of replacements aayenge, ab unsbme se max lelo
        int n=s.size();
        int i=0, j=0, maxf=0, maxlen=0;
        vector<int> freq(26);
        while(j<n){
            freq[s[j]-'A']++;
            maxf=max(maxf, freq[s[j]-'A']);
            if((j-i+1)-maxf>k){
                //shrink window
                freq[s[i]-'A']--;
                i++;
            }
            maxlen=max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};
