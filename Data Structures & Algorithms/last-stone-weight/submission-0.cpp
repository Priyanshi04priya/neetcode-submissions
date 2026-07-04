class Solution {
public:
    int f(priority_queue<int>& pq){
        if(pq.empty())return 0;
        if(pq.size()==1)return pq.top();
        int x=pq.top(); pq.pop();
        int y=pq.top();pq.pop();
        if(x==y)return f(pq);
        else {
            pq.push(x-y);
            return f(pq);
        }
        return 0;
    }
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        return f(pq);
    }
};
