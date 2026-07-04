class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> cap_pr;
        int n=profits.size();
        for(int i=0;i<n;i++){
            cap_pr.push_back({capital[i], profits[i]});
        }
        sort(cap_pr.begin(), cap_pr.end());
        priority_queue<int> pq;
        int prof=w;

        int i=0;
        while(k--){
            while(i<n && cap_pr[i].first<=prof){
                pq.push(cap_pr[i].second);
                i++;
            }
            if(!pq.empty()){
                auto top=pq.top(); pq.pop();
                prof+=top;
            }else break;
        }
        return prof;
    }
};