// class Solution {
// public:
//     bool isAlienSorted(vector<string>& words, string order) {
//         int position[26];
//         for(int i=0;i<order.size();i++){
//             position[order[i]-'a']=i;
//         }
//         auto cmp=[&](const string& a,const string& b){
//             for(int i=0;i<min(a.size(), b.size());i++){
//                 if(a[i]!=b[i]){
//                     return position[a[i]-'a']<position[b[i]-'a'];
//                 }
//             }
//             return a.size()<b.size();
//         };
//         return is_sorted(words.begin(), words.end(), cmp);
//     }
// };

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int position[26];
        int n=words.size();
        for(int i=0;i<order.size();i++){
            position[order[i]-'a']=i;
        }
        for(int i=1;i<n;i++){
            string w2=words[i];
            string w1=words[i-1];
            bool diff=false;
        
            for(int j=0;j<min(w1.size(), w2.size());j++){
                if(w1[j]!=w2[j]){
                    if(position[w1[j]-'a'] > position[w2[j]-'a'])return false;
                    diff=true;
                    break;
                }
            }
            if(!diff && w1.size()>w2.size())return false;  //"neetcode","neet"
        }
        return true;
    }
};