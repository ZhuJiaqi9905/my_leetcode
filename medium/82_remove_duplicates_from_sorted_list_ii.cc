#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  /// 删除链表元素的时候，Leetcode本身带的节点不用delete
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *dummy = new ListNode;
    dummy->next = head;

    ListNode *prev = dummy;
    ListNode *curr = dummy->next;
    ListNode *next = curr->next;
    while (next != nullptr) {
      if (next != nullptr && curr->val == next->val) {
        while (next != nullptr && curr->val == next->val) {
          curr->next = next->next;
          next = curr->next;
        }
        prev->next = curr->next;
        curr = prev->next;
        if (curr != nullptr) {
          next = curr->next;
        } else {
          break;
        }
      } else {
        prev = curr;
        curr = next;
        if (next == nullptr) {
          break;
        } else {
          next = next->next;
        }
      }
    }
    ListNode *res = dummy->next;
    delete dummy;
    return res;
  }
};
int main() {

  std::vector<ListNode> v{
      ListNode(1), ListNode(2), ListNode(3), ListNode(3),
      ListNode(4), ListNode(4), ListNode(5),
  };
  for (int i = 0, s = v.size(); i < s - 1; ++i) {
    v[i].next = &v[i + 1];
  }
  Solution s;
  s.deleteDuplicates(&v[0]);
}