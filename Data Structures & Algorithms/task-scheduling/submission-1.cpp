// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> freq(26,0);
//         for(char ch:tasks){
//             freq[ch-'A']++;
//         }
//         sort(freq.rbegin(), freq.rend());
//         int maxi=freq[0]-1;
//         int idle=maxi*n;

//         for(int i=1;i<26;i++){
//             idle-=min(freq[i], maxi);
//         }
//         idle=max(idle,0);
//         return tasks.size()+idle;
//     }
// };

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> freq(26,0);
        for(char ch:tasks){
            freq[ch-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0)pq.push(freq[i]);
        }
        //2ko sath pop karana hai 
        int ans=0;
        while(!pq.empty()){
            vector<int> temp;
            int wrkd=0;
            for(int i=0;i<n+1;i++){
                if(pq.empty()) break; 
                //jitne sapces hai hme unsb ke liye pop karane hai
                int top=pq.top();pq.pop();
                //decrease the corresponding freq
                top--;
                wrkd++;
                //jis jis ki freq dec hui hai and abhi bhi greater than zero hai un sbko temp me push
                if(top>0)temp.push_back(top);
            }
            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
            }
            if(pq.empty()) ans+=wrkd;
            else ans+=n+1;
        }
        return ans;
    }
};
