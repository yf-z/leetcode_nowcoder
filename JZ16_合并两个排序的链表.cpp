/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* head = new ListNode(1);
        ListNode* cur = head;
        ListNode* cur1 = pHead1, *cur2 = pHead2;
        
        while (cur1 || cur2) {
            if (cur1 && cur2) {
                if (cur1->val <= cur2->val) {
                    cur->next = cur1;
                    cur1 = cur1->next;
                    cur = cur->next;
                    cur->next = nullptr;
                }
                else {
                    cur->next = cur2;
                    cur2 = cur2->next;
                    cur = cur->next;
                    cur->next = nullptr;
                }
            }
            else {
                if (cur1) {
                    cur->next = cur1;
                    cur1 = cur1->next;
                    cur = cur->next;
                    cur->next = nullptr;
                }
                else {
                    cur->next = cur2;
                    cur2 = cur2->next;
                    cur = cur->next;
                    cur->next = nullptr;
                }
            }
        }
        
        return head->next;
    }
};