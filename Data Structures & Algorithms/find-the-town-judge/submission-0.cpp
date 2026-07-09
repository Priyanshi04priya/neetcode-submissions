class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n+1,0);
        vector<int> trusted(n+1,0);
        for(int i=0;i<trust.size();i++){
            v[trust[i][0]]=1;
            trusted[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(v[i]==0 && trusted[i]==n-1)return i;
        }
        return -1;
    }
};