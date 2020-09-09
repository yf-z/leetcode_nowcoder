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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int l = getL(pListHead);
        if (k == l)
            return pListHead;
        
        if (k > l)
            return nullptr;
        
        l = l-k;
        ListNode* cur = pListHead;
        while (l--) {
            cur = cur->next;
        }
        
        return cur;
    }
    
    int getL(ListNode* cur) {
        int count = 0;
        while (cur) {
            count++;
            cur = cur->next;
        }
        
        return count;
    }
};