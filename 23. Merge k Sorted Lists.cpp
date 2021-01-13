// Yifan Zhang
// 12/23/2020

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> processVector(vector<ListNode*> lists) {
        vector<ListNode*> re;
        for (auto it = lists.begin(); it != lists.end(); ++it) {
            if (*it != nullptr) {
                re.push_back(*it);
            }
        }
        
        return re;
    }
    
    int findMin(vector<ListNode*> &lists) {
        int cur_max = INT_MAX;
        int idx = 0;
        
        for (auto i = 0; i < lists.size(); ++i) {
            if (cur_max > (lists.at(i))->val) {
                cur_max = (lists.at(i))->val;
                idx = i;
            }
        }
        
        return idx;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        lists = processVector(lists);
        if (lists.empty())
            return nullptr;
        
        ListNode* head = new ListNode(0);
        ListNode* cur_node = head;
        
        // merge
        while (!lists.empty()) {
            int idx = findMin(lists);
            cur_node->next = lists.at(idx);
            lists.at(idx) = (lists.at(idx))->next;
            if (lists.at(idx) == nullptr) {
                lists.erase(lists.begin()+idx);
            }
            cur_node = cur_node->next;
        }
        
        return head->next;
    }
};