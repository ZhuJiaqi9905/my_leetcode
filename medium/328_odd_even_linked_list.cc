#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *ohead = head;       // odd head
    ListNode *ehead = head->next; // even head
    ListNode *op = ohead;
    ListNode *ep = ehead;
    ListNode *p = ehead->next;
    while (p != nullptr) {
      op->next = p;
      p = p->next;
      op = op->next;
      if (p == nullptr) {
        break;
      }
      ep->next = p;
      p = p->next;
      ep = ep->next;
    }
    op->next = ehead;
    ep->next = nullptr; // 这里要设置为nullptr,不然无限循环
    return ohead;
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
  Solution s1;
  s1.oddEvenList(&n1);
}