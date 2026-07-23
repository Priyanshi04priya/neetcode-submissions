// class MyHashSet {
// public: 
//     vector<bool> b;
//     MyHashSet() {
//         b.assign(10000001,false);
//     }
    
//     void add(int key) {
//         b[key]=true;
//     }
    
//     void remove(int key) {
//         b[key]=false;
//     }
    
//     bool contains(int key) {
//         return b[key];
//     }
// };

class MyHashSet {
    int prime;
    vector<list<int>> bucket;

    int hash(int key){
        return key%prime;
    }

public: 

    MyHashSet() {
        prime=10007;
        bucket.resize(prime);
    }
    
    void add(int key) {
        int ind=hash(key);
        //ab is index pr add kro
        if(!contains(key))bucket[ind].push_back(key);
    }
    
    void remove(int key) {
        int ind=hash(key);
        auto it=find(bucket[ind].begin(), bucket[ind].end(),key);
        if(it!=bucket[ind].end()){
            bucket[ind].erase(it);
        }
    }
    
    bool contains(int key) {
        int ind=hash(key);
        auto it=find(bucket[ind].begin(), bucket[ind].end(),key);
        return (it!=bucket[ind].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */