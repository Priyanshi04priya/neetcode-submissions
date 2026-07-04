class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        // if(m!=n)return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // for(int i=0;i<n;i++){
        //     if(s[i]!=t[i])return false;
        // }
        // return true;

        vector<int> hash1(26,0);
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            hash1[ch]++;
        }
        vector<int> hash2(26,0);
        for(int i=0;i<m;i++){
            int ch=t[i]-'a';
            hash2[ch]++;
        }
        for(int i=0;i<26;i++){
            if(hash1!=hash2)return false;
        }
        return true;
    }
};
