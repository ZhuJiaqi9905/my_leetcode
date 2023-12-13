struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
/// 先遍历右子树，再遍历左子树，再到根节点
class Solution {
public:
  TreeNode *prev_;
  void flatten(TreeNode *root) { dfs(root); }

  void dfs(TreeNode *node) {
    if (node == nullptr) {
      return;
    }
    dfs(node->right);
    dfs(node->left);
    node->left = nullptr;
    node->right = prev_;
    prev_ = node;
  }
};
int main() {}