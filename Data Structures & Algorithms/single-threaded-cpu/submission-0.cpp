class Solution {
public:
    typedef pair<int,int> p;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i); //storing its index to secure 
        }
        sort(tasks.begin(), tasks.end());
        int curr_time=tasks[0][0]; //start time
        int i=0;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> ans;

        while(i<n || !pq.empty()){
            while(i<n && tasks[i][0]<=curr_time){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            if(!pq.empty()){
                //processing time ke according execute
                auto top=pq.top(); pq.pop();
                curr_time+=top.first;
                ans.push_back(top.second);
            }
            else{
                curr_time=tasks[i][0];
            }
        }
        return ans;
    }
};