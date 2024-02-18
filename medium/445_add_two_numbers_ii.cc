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
  ListNode *dfs(ListNode *l1, ListNode *l2, int d1, int d2) {
    ListNode *nd = new ListNode();
    if (d1 > d2) {
      ListNode *next = dfs(l1->next, l2, d1 - 1, d2);
      nd->next = next;
      nd->val = l1->val;
      if (next->val >= 10) {
        nd->val += next->val / 10;
        next->val = next->val % 10;
      }
      return nd;
    } else if (d1 < d2) {
      ListNode *next = dfs(l1, l2->next, d1, d2 - 1);
      nd->next = next;
      nd->val = l2->val;
      if (next->val >= 10) {
        nd->val += next->val / 10;
        next->val = next->val % 10;
      }
      return nd;
    }
    int val = l1->val + l2->val;
    if (d1 == 1) {
      nd->val = val;
      return nd;
    }
    ListNode *next = dfs(l1->next, l2->next, d1 - 1, d2 - 1);
    nd->next = next;
    nd->val = next->val / 10 + val;
    next->val = next->val % 10;
    return nd;
  }
  int getLen(ListNode *nd) {
    int len = 0;
    while (nd != nullptr) {
      nd = nd->next;
      len++;
    }
    return len;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1->val == 0) {
      return l2;
    }
    if (l2->val == 0) {
      return l1;
    }
    int n1 = getLen(l1);
    int n2 = getLen(l2);
    ListNode *nd = dfs(l1, l2, n1, n2);
    if (nd->val >= 10) {
      ListNode *head = new ListNode(nd->val / 10, nd);
      nd->val = nd->val % 10;
      return head;
    } else {
      return nd;
    }
  }
};
int main() {}