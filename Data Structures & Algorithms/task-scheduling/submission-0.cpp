class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char ch:tasks){
            freq[ch-'A']++;
        }
        sort(freq.rbegin(), freq.rend());
        int maxi=freq[0]-1;
        int idle=maxi*n;

        for(int i=1;i<26;i++){
            idle-=min(freq[i], maxi);
        }
        idle=max(idle,0);
        return tasks.size()+idle;
    }
};
