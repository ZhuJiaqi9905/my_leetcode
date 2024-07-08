struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *findReplicateNodes(ListNode *head) {
    ListNode *p = head->next;
    while (p != nullptr && p->val == head->val) {
      p = p->next;
    }
    return p;
  }
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *p = head;
    while (p != nullptr) {
      ListNode *nx = findReplicateNodes(p);
      p->next = nx;
      p = nx;
    }
    return head;
  }
};