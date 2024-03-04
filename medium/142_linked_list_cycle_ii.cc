
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *quick = head;
    ListNode *slow = head;

    while (true) {
      if (quick == nullptr) {
        return nullptr;
      }
      quick = quick->next;
      if (quick == nullptr) {
        return nullptr;
      }
      quick = quick->next;
      slow = slow->next;
      if (quick == slow) {
        break;
      }
    }
    ListNode *p = head;
    while (p != slow) {
      p = p->next;
      slow = slow->next;
    }
    return p;
  }
};
int main() {}