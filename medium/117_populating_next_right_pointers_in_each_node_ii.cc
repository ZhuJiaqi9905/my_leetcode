#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (root == nullptr) {
      return root;
    }
    deque<Node *> que;
    que.emplace_back(root);

    while (!que.empty()) {
      Node *prev = nullptr;
      for (int i = 0, n = que.size(); i < n; ++i) {
        Node *node = que.front();
        que.pop_front();
        if (node->left != nullptr) {
          que.emplace_back(node->left);
        }
        if (node->right != nullptr) {
          que.emplace_back(node->right);
        }
        if (i != n - 1) {
          node->next = que.front();
        }
      }
    }
    return root;
  }
};

int main() {}