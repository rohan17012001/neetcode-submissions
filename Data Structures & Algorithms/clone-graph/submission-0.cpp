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
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> m;
        Node* temp=new Node(node->val);
        m[node]=temp;
        if(node->neighbors.empty()) return temp;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* qnode=q.front();
            q.pop();
            for(auto i: qnode->neighbors){
                if(m.find(i)==m.end()){
                    Node* nnode=new Node(i->val);
                    m[qnode]->neighbors.push_back(nnode);
                    q.push(i);
                    m[i]=nnode;
                }
                else{
                    m[qnode]->neighbors.push_back(m[i]);
                }
            }
        }
        return m[node];
    }
};
