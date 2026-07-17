class Solution {
public:
    int bfs(string start,unordered_set<string>& wl,string end){
        queue<pair<string,int>> q;
        q.push({start,1});
        while(!q.empty()){
            auto [start,level]=q.front(); q.pop();
            if(start==end)return level;
            for(int i=0;i<start.size();i++){
                char ch=start[i];
                for(char c='a';c<='z';c++){
                    start[i]=c;
                    if(wl.count(start)){
                        wl.erase(start);
                        q.push({start,level+1});
                    }
                }
                start[i]=ch;
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(!st.count(endWord))return 0;
        return bfs(beginWord,st,endWord);
    }
};
