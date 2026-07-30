class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(ans.back()[1]>=intervals[i][0]){
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            }
            else ans.push_back(intervals[i]);
        }
        return ans;
        //as it is already sorted apply binary search to insert the interval at correct position
    }
};
