class Solution {
public:
    typedef pair<double,pair<int,int>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p> pq;
        //cal distances
        for(auto it:points){
            int x=it[0];
            int y=it[1];
            double dist = sqrt(pow(x,2) + pow(y,2));
            pq.push({dist,{x,y}});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto it=pq.top();
            ans.push_back({it.second.first, it.second.second});
            pq.pop();
        }
        return ans;
    }
};
