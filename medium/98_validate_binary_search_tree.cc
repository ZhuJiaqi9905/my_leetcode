#include <limits>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
/// dfs并维护子树的最大值和最小值
class Solution {
public:
  bool isValidBST(TreeNode *root) {
    int min_val = 0;
    int max_val = 0;
    return dfs(root, min_val, max_val);
  }

  bool dfs(TreeNode *root, int &min_val, int &max_val) {
    if (root->left == nullptr && root->right == nullptr) {
      min_val = max_val = root->val;
      return true;
    }
    if (root->right != nullptr && root->left == nullptr) {

      auto min_right = std::numeric_limits<int>::max();
      auto max_right = std::numeric_limits<int>::min();
      bool res = dfs(root->right, min_right, max_right);
      if (res == false || root->val >= min_right) {
        return false;
      }
      min_val = root->val;
      max_val = max_right;
      return true;
    }
    if (root->right == nullptr && root->left != nullptr) {
      auto min_left = std::numeric_limits<int>::max();
      auto max_left = std::numeric_limits<int>::min();
      bool res = dfs(root->left, min_left, max_left);
      if (res == false || max_left >= root->val) {
        return false;
      }
      min_val = min_left;
      max_val = root->val;
      return true;
    }
    auto min_left = std::numeric_limits<int>::max();
    auto max_left = std::numeric_limits<int>::min();
    auto min_right = std::numeric_limits<int>::max();
    auto max_right = std::numeric_limits<int>::min();

    bool res_left = dfs(root->left, min_left, max_left);
    bool res_right = dfs(root->right, min_right, max_right);
    if (res_left == false || res_right == false || max_left >= root->val ||
        root->val >= min_right) {
      return false;
    }
    min_val = min_left;
    max_val = max_right;
    return true;
  }
};