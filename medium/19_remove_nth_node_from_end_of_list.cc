struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int n_;
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    n_ = n;
    int id = getAndRemoveNthIdFromEnd(head);
    if (id == n_) {
      ListNode *nd = head;
      head = head->next;
      delete nd;
    }
    return head;
  }

  int getAndRemoveNthIdFromEnd(ListNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int my_id = getAndRemoveNthIdFromEnd(node->next) + 1;
    if (my_id == n_ + 1) {
      ListNode *nd = node->next;
      node->next = nd->next;
      delete nd;
    }
    return my_id;
  }
};
int main() {
  Solution s1;
  ListNode *h1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  h1->next = n2;

  s1.removeNthFromEnd(h1, 2);
}