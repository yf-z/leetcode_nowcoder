#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

void printList(RandomListNode* cur) {
  while (cur) {
    cout << cur->label << " ";
    if (cur->random)
      cout << "random: " << cur->random->label;
    cout << endl;
    cur = cur->next;
  }
  cout << endl;
}


bool compare(RandomListNode* p1, RandomListNode* p2) {
  while (p1 && p2) {

    if (p1 == p2) {
      cout << p1->label << endl;
    }

    if (p1->random == p2->random) {
      cout << "random\n";
      cout << p1->label << " " << p2->label <<  endl;
    }
    
    p1 = p1->next;
    p2 = p2->next;
  }

  return (!(p1 == p2));
}

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return nullptr;
        
        RandomListNode* cur = pHead;
        while (cur) {
            RandomListNode* temp = new RandomListNode(cur->label*10);
            temp->next = cur->next;
            temp->random = cur->random;
            cur->next = temp;
            cur = cur->next->next;
        }
        
        cur = pHead;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            else
              {
                cur->next->random = NULL;
              }
            
            cur = cur->next->next;
        }
        
        RandomListNode* head= pHead->next;
        cur = pHead;
        while (cur) {
            RandomListNode* next = cur->next->next;
            if (next)
              cur->next->next = next->next;
            else
              cur->next->next = NULL;
            
            
            cur->next = next;
            
            cur = cur->next;
        }

        return head;
    }
};

int main() {
  RandomListNode* p1 = new RandomListNode(1);
  RandomListNode* p2 = new RandomListNode(2);
  RandomListNode* p3 = new RandomListNode(3);
  RandomListNode* p4 = new RandomListNode(4);
  RandomListNode* p5 = new RandomListNode(5);
  p1->random = p3;
  p2->random = p5;
  p4->random = p2;
  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;

  Solution test;
  RandomListNode* re = test.Clone(p1);

  printList(re);
  cout << "compare:1\n";
  if (!compare(p1, re))
    cout << "The last one";
}