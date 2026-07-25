class MyHashMap {
    int prime=10007;
    vector<list<pair<int,int>>> bucket;

public:
    int hash(int key){
        return key%prime;
    }
    MyHashMap() {
        bucket.resize(prime);
    }
    
    void put(int key, int value) {
        int ind=hash(key);
        for(auto& it:bucket[ind]){
            if(it.first==key){
                it.second=value;
                return;
            }
        }
        bucket[ind].push_back({key,value});
    }
    
    int get(int key) {
        int ind=hash(key);
        for(auto& it:bucket[ind]){
            if(it.first==key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int ind=hash(key);
        for(auto it=bucket[ind].begin(); it!=bucket[ind].end(); it++){
            if(it->first==key){
                bucket[ind].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */