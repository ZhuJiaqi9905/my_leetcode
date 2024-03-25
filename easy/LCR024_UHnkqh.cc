struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *reverseList(ListNode *head) {

    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *p;
    p = head;
    ListNode *p1 = p->next;
    while (p1 != nullptr) {
      ListNode *next = p1->next;
      p1->next = p;
      p = p1;
      p1 = next;
    }
    head->next = nullptr;
    return p;
  }
};