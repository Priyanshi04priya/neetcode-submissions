class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n=s.size();
        vector<int> index(26);
        for(int i=0;i<n;i++){
            index[s[i]-'a']=i;
        }
        int low=0, high=index[s[0]-'a'];
        while(low<n){
            int i=low;
            while(i<=high){
                high=max(high, index[s[i]-'a']);
                i++;
            }
            ans.push_back(high-low+1);
            low=high+1;
            if(low<n) high=index[s[low]-'a'];
        }
        return ans;
    }
};
