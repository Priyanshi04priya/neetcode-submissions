class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>& b)const{
            if(a[1]==b[1])return a[0]<b[0];
            return a[1]<b[1];
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),cmp());
        int cnt=0;
        int lastEnd=intervals[0][1];
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(lastEnd>intervals[i][0]){
                cnt++;
            }
            else lastEnd=intervals[i][1];
        }
        return cnt;
    }
};
