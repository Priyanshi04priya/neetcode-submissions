class Solution {
public:
    vector<string> neigh(string str){
        vector<string> ans;
        for(int i=0;i<4;i++){
            char ch=str[i];
            string s=str;
            int inc=(ch=='9')?0:(ch-'0')+1;
            int dec=(ch=='0')?9:(ch-'0')-1;
            s[i]=inc+'0';
            ans.push_back(s);
            s[i]=dec+'0';
            ans.push_back(s);
        }
        return ans;
    }
    int openLock(vector<string>& de, string t) {
        unordered_set<string> st(de.begin(), de.end());
        if(st.count("0000"))return -1;

        queue<pair<string,int>> q;
        q.push({"0000",0});
        st.insert("0000");

        while(!q.empty()){
            auto [str,cost]=q.front(); q.pop();
            if(str==t)return cost;
            for(auto& it:neigh(str)){
                if(!st.count(it)){
                    st.insert(it);
                    q.push({it,cost+1});
                }
            }
        }
        return -1;
    }
};