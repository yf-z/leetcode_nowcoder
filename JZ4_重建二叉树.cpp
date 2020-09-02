/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
*   Written By
*   Yifan Zhang
*/

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return cons(pre, vin, 0, pre.size());
    }
    
    TreeNode* cons(vector<int> &pre, vector<int>& vin, int s, int e) {
        if (s >= e || pre.empty())
            return nullptr;
            
        TreeNode* cur = new TreeNode(pre.front());
        
        int middle = 0;
        for (int i = s; i < e; i++) {
            if (vin[i] == pre.front()) {
                middle = i;
                break;
            }
        }
        
        pre.erase(pre.begin());
        cur->left = cons(pre, vin, s, middle);
        cur->right = cons(pre, vin, middle+1, e);
        
        return cur;
    }
};