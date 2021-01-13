// Yifan Zhang
// 01/12

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node)
            return;
        
        ListNode* curNode = node;
        while (curNode && curNode->next && curNode->next->next) {
            curNode->val = curNode->next->val;
            curNode = curNode->next;
        }
        
        if (curNode && curNode->next)
            curNode->val = curNode->next->val;
        curNode->next = nullptr;
        return;
    }
};