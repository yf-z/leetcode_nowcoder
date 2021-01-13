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
    void Mirror(TreeNode *pRoot) {
        swap(pRoot);
        return;
    }
    
    void swap(TreeNode* root) {
        if (!root)
            return;
        
        swap(root->left);
        swap(root->right);
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return;
    }
};