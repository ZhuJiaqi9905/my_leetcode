
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    targetSum -= root->val;
    if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
      return true;
    }
    if (root->left != nullptr) {
      bool ans = hasPathSum(root->left, targetSum);
      if (ans == true) {
        return true;
      }
    }
    if (root->right != nullptr) {
      bool ans = hasPathSum(root->right, targetSum);
      if (ans == true) {
        return true;
      }
    }
    return false;
  }
};