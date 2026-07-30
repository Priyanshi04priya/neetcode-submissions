class Solution {
public:
    int calPoints(vector<string>& op) {
        long long sum=0;
        int n=op.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(op[i]=="+"){
                int x=ans[ans.size()-1]+ans[ans.size()-2];
                ans.push_back(x);
                sum+=x;
            }
            else if(op[i]=="C"){
                sum-=ans.back();
                ans.pop_back();
            }
            else if(op[i]=="D"){
                int d=(2*ans.back());
                sum+=d;
                ans.push_back(d);
            }
            else{
                int x=stoi(op[i]);
                ans.push_back(x);
                sum+=x;
            }
        }
        return (int)sum;
    }
};