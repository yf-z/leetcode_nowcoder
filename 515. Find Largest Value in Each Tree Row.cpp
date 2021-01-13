/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
// Yifan Zhang
// 01/12
 
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        
        vector<pair<TreeNode*, int>> queue;
        queue.push_back(pair<TreeNode*, int>(root, 0));
        
        vector<int> sum;
        
        while (!queue.empty()) {
            TreeNode* curNode = queue.front().first;
            int curLevel = queue.front().second;
            
            if (curLevel < sum.size()) {
                sum[curLevel] = max(curNode->val, sum[curLevel]);
            }
            else
                sum.push_back(curNode->val);
            
            if (curNode->left) {
                queue.push_back(pair<TreeNode*, int>(curNode->left, curLevel+1));
            }
            
            if (curNode->right) {
                queue.push_back(pair<TreeNode*, int>(curNode->right, curLevel+1));
            }
            
            queue.erase(queue.begin());
        }
        
        return sum;
    }
};