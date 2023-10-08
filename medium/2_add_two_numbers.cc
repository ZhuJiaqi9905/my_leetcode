/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr;
    ListNode *pNode = nullptr;
    if (l1 == nullptr && l2 == nullptr) {
      return head;
    }
    int carry = 0; //进位
    int val = 0;

    while (l1 != nullptr || l2 != nullptr) {
      val =
          (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
      if (head == nullptr) { //如果是头结点
        head = pNode = new ListNode();
      } else { //其余情况
        pNode->next = new ListNode();
        pNode = pNode->next;
      }

      pNode->val = val % 10;
      carry = val / 10;

      if (l1 != nullptr)
        l1 = l1->next;
      if (l2 != nullptr)
        l2 = l2->next;
    }
    if (carry != 0) {
      pNode->next = new ListNode(carry);
    }
    return head;
  }
};