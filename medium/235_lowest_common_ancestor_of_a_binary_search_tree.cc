#include <cstddef>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  inline int sgn(int x) {
    if (x > 0) {
      return 1;
    } else if (x == 0) {
      return 0;
    } else {
      return -1;
    }
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (sgn(root->val - p->val) * sgn(root->val - q->val) > 0) {
      if (root->val > p->val) {
        return lowestCommonAncestor(root->left, p, q);
      } else {
        return lowestCommonAncestor(root->right, p, q);
      }
    } else {
      return root;
    }
  }
};