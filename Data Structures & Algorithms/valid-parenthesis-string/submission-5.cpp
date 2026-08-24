class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*')star.push(i);
            else if(s[i]=='(')st.push(i);
            else{
                if(!st.empty())st.pop();
                else{
                    if(!star.empty())star.pop();
                    else return false;
                }
            }
        }
        //star ( se phle nhi hona chahiye
        while(!st.empty() && !star.empty()){
            if(st.top()>star.top())return false;
            st.pop();
            star.pop();
        }
        return st.empty();
    }
};
