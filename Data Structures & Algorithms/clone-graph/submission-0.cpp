/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* start,unordered_map<Node*,Node*>& mpp){
        mpp[node]=start;
        for(auto it:node->neighbors){
            if(!mpp.count(it)){
                Node* newnode=new Node(it->val);
                start->neighbors.push_back(newnode);
                mpp[it]=newnode;
                dfs(it,newnode,mpp);
            }
            else{
                start->neighbors.push_back(mpp[it]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*,Node*> mpp;
        Node* start=new Node(node->val);
        dfs(node,start,mpp);
        return start;
    }
};
