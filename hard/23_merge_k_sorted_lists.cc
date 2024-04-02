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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return nullptr;
    }
    int len = lists.size();
    int k = 1;
    while (k < len) {
      for (int i = 0; i < len - k; i += k * 2) {
        lists[i] = mergeTwoLists(lists[i], lists[i + k]);
      }
      k *= 2;
    }
    return lists[0];
  }

  ListNode *mergeTwoLists(ListNode *la, ListNode *lb) {
    if (la == nullptr) {
      return lb;
    }
    if (lb == nullptr) {
      return la;
    }
    if (la->val < lb->val) {
      la->next = mergeTwoLists(la->next, lb);
      return la;
    } else {
      lb->next = mergeTwoLists(la, lb->next);
      return lb;
    }
  }
};