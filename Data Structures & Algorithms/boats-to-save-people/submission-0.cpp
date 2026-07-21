class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(), p.end());
        int i=0, j=p.size()-1;
        int cnt=0;
        while(i<=j){
            if(p[i]+p[j]<=limit){
                cnt++;
                i++;
                j--;
            }
            else {
                j--;
                cnt++;
            }
        }
        return cnt;
    }
};