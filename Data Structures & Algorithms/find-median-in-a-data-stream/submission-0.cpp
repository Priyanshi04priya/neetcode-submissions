class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    MedianFinder() { 
    }
    
    void addNum(int num) {
        if (maxpq.empty() || num <= maxpq.top())maxpq.push(num);
        else minpq.push(num);
        if(maxpq.size()>minpq.size()+1){
            int top=maxpq.top(); maxpq.pop();
            minpq.push(top);
        }
        else if(maxpq.size()<minpq.size()){
            int top=minpq.top(); minpq.pop();
            maxpq.push(top);
        }
    }
    
    double findMedian() {
        if(maxpq.size()>minpq.size())return maxpq.top();
        return (maxpq.top()+minpq.top())/2.0;
    }
};
