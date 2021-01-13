// Yifan Zhang
// 12/27/2020

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sum(TreeNode* cur, int & res) {
        if (!cur)
            return;
        
        if (cur->val % 2 == 0) {
            if (cur->left) {
                if (cur->left->left)
                    res += cur->left->left->val;
                
                if (cur->left->right)
                    res += cur->left->right->val;
            }
            
            if (cur->right) {
                if (cur->right->left)
                    res += cur->right->left->val;
                
                if (cur->right->right)
                    res += cur->right->right->val;
            }
        }
        
        sum(cur->left, res);
        sum(cur->right, res);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        sum(root, res);
        return res;
    }
};