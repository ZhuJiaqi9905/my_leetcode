struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/// 用两个哨兵节点small和large。
class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *small = new ListNode;
    ListNode *small_head = small;
    ListNode *large = new ListNode;
    ListNode *large_head = large;
    ListNode *iter = head;
    while (iter != nullptr) {
      if (iter->val < x) {
        small->next = iter;
        small = small->next;
      } else {
        large->next = iter;
        large = large->next;
      }
      iter = iter->next;
    }
    large->next = nullptr;
    small->next = large_head->next;
    ListNode *res = small_head->next;
    delete large_head;
    delete small_head;
    return res;
  }
};
int main() {}