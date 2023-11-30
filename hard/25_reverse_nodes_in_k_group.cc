struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode;
    dummy->next = head;

    ListNode *start = dummy;
    ListNode *end = start;
    while (true) {
      for (int i = 0; i < k; ++i) {
        if (end != nullptr) {
          end = end->next;
        } else { // 到末尾了
          ListNode *res = dummy->next;
          delete dummy;
          return res;
        }
      }
      if (end == nullptr) {
        break;
      }
      // 注意这里要存储end->next,并在翻转后修改
      ListNode *end_next = end->next;
      start = reverseList(start, end);
      start->next = end_next;
      end = start;
    }
    ListNode *res = dummy->next;
    delete dummy;
    return res;
  }
  ListNode *reverseList(ListNode *start, ListNode *end) {
    ListNode *curr = start->next;
    ListNode *next = curr->next;

    while (curr != end) {
      ListNode *nd = next->next;
      next->next = curr;
      curr = next;
      next = nd;
    }
    // 这里
    ListNode *new_end = start->next;
    start->next = curr;
    return new_end;
  }
};

int main() {
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  Solution s;
  s.reverseKGroup(&n1, 2);
}