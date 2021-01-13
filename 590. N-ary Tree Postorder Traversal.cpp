// Yifan Zhang
// 01/12


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void po(Node* curNode, vector<int> &res) {
        if (!curNode) {
            return;
        }
        
        for (auto it = curNode->children.begin(); it != curNode->children.end(); ++it) {
            po(*it, res);
        }
        
        res.push_back(curNode->val);
        return;
    }
    
    vector<int> postorder(Node* root) {
        if (!root)
            return {};
        
        vector<int> res;
        po(root, res);
        return res;
    }
};