#include <cstddef>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }
    Node *new_head = new Node(head->val);
    Node *nd = head->next;
    Node *curr = new_head;
    unordered_map<Node *, Node *> mp;
    mp[head] = new_head;
    while (nd != nullptr) {
      curr->next = new Node(nd->val);
      mp[nd] = curr->next;
      curr = curr->next;
      nd = nd->next;
    }
    nd = head;
    curr = new_head;
    while (nd != nullptr) {
      curr->random = mp[nd->random];
      nd = nd->next;
      curr = curr->next;
    }
    return new_head;
  }

  // 解法2：递归
  unordered_map<Node *, Node *> cachedNode;

  Node *copyRandomList2(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }
    if (!cachedNode.count(head)) {
      Node *headNew = new Node(head->val);
      cachedNode[head] = headNew;
      headNew->next = copyRandomList(head->next);
      headNew->random = copyRandomList(head->random);
    }
    return cachedNode[head];
  }
};