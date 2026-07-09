class Solution {
public:
    
    bool isAlienSorted(vector<string>& words, string order) {
        int position[26];
        for(int i=0;i<order.size();i++){
            position[order[i]-'a']=i;
        }
        auto cmp=[&](const string& a,const string& b){
            for(int i=0;i<min(a.size(), b.size());i++){
                if(a[i]!=b[i]){
                    return position[a[i]-'a']<position[b[i]-'a'];
                }
            }
            return a.size()<b.size();
        };
        return is_sorted(words.begin(), words.end(), cmp);
    }
};