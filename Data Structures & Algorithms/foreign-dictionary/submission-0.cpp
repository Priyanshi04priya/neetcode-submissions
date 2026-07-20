class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char,int> ind;
        //initialization of indegree and adj
        for(string s:words){
            for(char ch:s){
                adj[ch]=unordered_set<char>();
                ind[ch]=0;
            }
        }

        for(int i=0;i<words.size()-1;i++){
            string w1=words[i], w2=words[i+1];
            int minlen=min(w1.size(), w2.size());
            //invalid case e.g leetcode comes before leet
            if(w1.size()>w2.size() and w1.substr(0,minlen)==w2.substr(0,minlen))return ""; 
            
            //adjlist and indegree formation
            for(int j=0;j<minlen;j++){
                if(w1[j]!=w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        ind[w2[j]]++;
                    }
                    //agar equal hai to break;
                    break;
                }
            }
        }

        //toposort
        queue<char> q;
        for(auto &[c,deg]:ind){
            if(deg==0)q.push(c);
        }
        string ans;
        while(!q.empty()){
            char c=q.front(); q.pop();
            ans+=c;
            for(char it:adj[c]){
                ind[it]--;
                if(ind[it]==0)q.push(it);
            }
        }
        //cycle check
        if(ans.size()!=ind.size()) return "";
        return ans;
    }
};
