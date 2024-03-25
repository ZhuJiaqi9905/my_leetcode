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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }
    if (list1->val > list2->val) {
      swap(list1, list2);
    }
    ListNode *h = list1; // 用一个新的头
    ListNode *p1 = list1->next;
    ListNode *p2 = list2;

    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val <= p2->val) {
        h->next = p1;
        p1 = p1->next;
      } else {
        h->next = p2;
        p2 = p2->next;
      }
      h = h->next;
    }
    h->next = (p1 == nullptr) ? p2 : p1;
    return list1;
  }
};
