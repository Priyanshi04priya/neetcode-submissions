// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         map<string, vector<string>> mpp;
//         for(auto word:strs){
//             auto key=word;
//             sort(key.begin(), key.end());
//             mpp[key].push_back(word);
//         }
//         vector<vector<string>> ans;
//         for(auto it:mpp){
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mpp;
        for(auto word:strs){
            vector<int> freq(26);
            for(auto ch:word){
                freq[ch-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+='#'+to_string(freq[i]); // '#' separates counts so "11" and "1,1" are not confused
            }
            mpp[key].push_back(word);
        }
        vector<vector<string>> ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
