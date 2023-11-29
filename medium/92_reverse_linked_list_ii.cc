struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {

    ListNode *curr = head;
    ListNode *left_prev = nullptr; // 记录left的前一个节点
    if (left > 1) {
      for (int i = 1; i < left - 1; ++i) {
        curr = curr->next;
      }
      left_prev = curr;
      curr = curr->next;
    }
    ListNode *n_left = curr; // 记录left节点
    ListNode *next = curr->next;
    for (int i = left; i < right; ++i) {
      ListNode *nd = nullptr;
      if (next != nullptr) {
        nd = next->next;
      }
      next->next = curr;
      curr = next;
      next = nd;
    }
    if (left_prev != nullptr) {
      left_prev->next = curr;
    }
    n_left->next = next;
    // 如果反转起始的位置是头部，新链表头的位置是变的
    if (left > 1) {
      return head;

    } else {
      return curr;
    }
  }
};