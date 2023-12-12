
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
  int ans_{0};
  int sumNumbers(TreeNode *root) {
    int tmp = 0;
    dfs(root, tmp);
    return ans_;
  }
  void dfs(TreeNode *node, int tmp_ans) {
    int val = tmp_ans * 10 + node->val;
    if (node->left == nullptr && node->right == nullptr) {
      ans_ += val;
      return;
    }
    if (node->left != nullptr) {
      dfs(node->left, val);
    }
    if (node->right != nullptr) {
      dfs(node->right, val);
    }
    return;
  }
};