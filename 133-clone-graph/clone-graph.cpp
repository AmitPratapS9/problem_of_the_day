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
    vector<Node*> nodeRegister;
    void dfs(Node* node, Node* clone)
    {
        for(auto neighbour:node->neighbors)
        {
            //if node is not created, we create the node
            if(!nodeRegister[neighbour->val]) 
            {
                Node* newNode=new Node(neighbour->val);
                nodeRegister[newNode->val]=newNode;
                clone->neighbors.push_back(newNode);
                dfs(neighbour,newNode);
            }
            else
            {
                clone->neighbors.push_back(nodeRegister[neighbour->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        
        Node* clone=new Node(node->val);
        nodeRegister.resize(101,NULL);
        nodeRegister[clone->val]=clone;
        dfs(node,clone);
        return clone;
    }
};