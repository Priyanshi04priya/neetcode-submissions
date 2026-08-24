/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int rooms=0;
        //ordered map
        map<int,int> mpp;
        for(auto it:intervals){
            mpp[it.start]++;
            mpp[it.end]--;
        }
        int max_overlap=0, overlap=0;
        for(auto it:mpp){
            overlap+=it.second;
            max_overlap=max(max_overlap, overlap);
        }
        return max_overlap;
    }
};
