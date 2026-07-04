#include <bits/stdc++.h>

class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if (strs.empty()) return "";
        string to_find=strs[0];
        for(int i=0;i<n;i++){
            while (strs[i].find(to_find)==string::npos) {  
                to_find.pop_back();
                if (to_find.empty()) return "";
            }
        }
        return to_find;
    }
};