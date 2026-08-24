class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int f=target[0], s=target[1], t=target[2];
        int maxf=0, maxs=0, maxt=0;
        for(auto it:triplets){
            if(it[0]<=f && it[1]<=s && it[2]<=t){
                maxf=max(maxf,it[0]);
                maxs=max(maxs,it[1]);
                maxt=max(maxt,it[2]);
            }
        }

        return (maxf==f && maxs==s && maxt==t);
    }
};
