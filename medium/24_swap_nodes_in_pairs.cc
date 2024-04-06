struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *nd = new ListNode();
    ListNode *prev = nd;
    prev->next = head;
    ListNode *p = head;
    ListNode *pn = head->next;
    while (true) {
      prev->next = pn;
      p->next = pn->next;
      pn->next = p;

      prev = p;
      if (p->next == nullptr) {
        break;
      }
      p = p->next;
      if (p->next == nullptr) {
        break;
      }
      pn = p->next;
    }
    return nd->next;
  }
};