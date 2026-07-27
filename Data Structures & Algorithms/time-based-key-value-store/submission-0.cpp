class TimeMap {
    unordered_map<string, vector<pair<int,string>>> mpp;
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& values=mpp[key];
        int low=0, high=values.size()-1;
        string ans="";
        while(low<=high){
            int mid=low+(high-low)/2;
            if(values[mid].first<=timestamp){
                ans=values[mid].second;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
