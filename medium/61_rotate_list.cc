struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/// 先连成环，再移动，最后断开。
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || k == 0 || head->next == nullptr) {
      return head;
    }
    int n = 1;
    ListNode *iter = head;
    while (iter->next != nullptr) {
      iter = iter->next;
      n++;
    }
    int rotate = n - k % n;
    if (rotate == n) {
      return head;
    }
    iter->next = head;
    while (rotate--) {
      iter = iter->next;
    }
    ListNode *new_head = iter->next;
    iter->next = nullptr;
    return new_head;
  }
};
int main() {}