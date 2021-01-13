/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (!root)
            return {};
        
        vector<int> re;
        queue<TreeNode*> nodes;
        nodes.push(root);
        BFS(re, nodes);
        
        return re;
    }
    
    void BFS(vector<int> &re, queue<TreeNode*> nodes) {
        while (!nodes.empty()) {
            TreeNode* cur = nodes.front();
            nodes.pop();
            re.push_back(cur->val);
            if (cur->left)
                nodes.push(cur->left);
            
            if (cur->right)
                nodes.push(cur->right);
        }
        
        return;
    }
};