class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) return false;
        vector<int> freq1(26), freq2(26);
        for(auto it:s1){
            freq1[it-'a']++;
        }
        //1st window
        int k=s1.size();
        for(int i=0;i<k;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2)return true;
        for(int i=k;i<s2.size();i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-k]-'a']--;
            if(freq1==freq2)return true;
        }
        return false;
    }
};
