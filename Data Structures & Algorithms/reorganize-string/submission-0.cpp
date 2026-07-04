class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        if(n==1) return s;
        unordered_map<char,int> mpp; //char -> freq
        for(char ch:s){
            mpp[ch]++;
            if(mpp[ch]>(n+1)/2) return "";
        }
        
        //map ke items pq me
        priority_queue<pair<int,char>> pq;
        for(auto it: mpp){
            pq.push({it.second, it.first});
        }

        string res="";
        while(pq.size()>1){
            auto [f1,c1]=pq.top();pq.pop();
            auto [f2,c2]=pq.top();pq.pop();
            res+=c1;
            res+=c2;
            f1--;
            f2--;
            if(f1>0)pq.push({f1,c1});
            if(f2>0)pq.push({f2,c2});
        }
        if(!pq.empty())res+=pq.top().second;  //jb pq me 1 hi element remaining ho
        return res;
    }
};