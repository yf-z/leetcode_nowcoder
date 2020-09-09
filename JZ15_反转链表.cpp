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
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead)
            return pHead;
        
        ListNode* cur = pHead;
        ListNode* tail = getTail(cur);
        while (cur != tail) {
            ListNode* temp = cur;
            cur = cur->next;
            temp->next = tail->next;
            tail->next = temp;
        }
        
        return tail;
    }
    
    ListNode* getTail(ListNode* cur) {
        while (cur->next) {
            cur = cur->next;
        }
        
        return cur;
    }
};