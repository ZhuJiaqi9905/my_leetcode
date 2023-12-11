#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
  TreeNode *curr_;
  stack<TreeNode *> stk_;
  BSTIterator(TreeNode *root) : curr_(root) {}

  int next() {
    while (curr_ != nullptr) {
      stk_.emplace(curr_);
      curr_ = curr_->left;
    }
    curr_ = stk_.top();
    stk_.pop();
    int ans = curr_->val;
    curr_ = curr_->right;
    return ans;
  }

  bool hasNext() { return curr_ != nullptr || !stk_.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */