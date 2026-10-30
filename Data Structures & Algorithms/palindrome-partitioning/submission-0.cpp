class Solution {
public:
    bool ispalin(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])return false;
        }
        return true;
    }

    void f(int i, string s, vector<vector<string>>& res, vector<string> &ans){
        int n=s.size();

        if(i==n){
            res.push_back(ans);
            return;
        }

        for(int j=i;j<n;j++){
            string str=s.substr(i,j-i+1);
            if(ispalin(str)){
                ans.push_back(str);
                f(j+1,s,res,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        f(0,s,res,ans);
        return res;
    }
};
