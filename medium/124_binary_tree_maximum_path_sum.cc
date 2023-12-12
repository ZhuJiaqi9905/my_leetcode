#include <algorithm>
#include <limits>
#include <unordered_map>
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
/// dp[i]表示对于node i，在node i是路径的端点的条件下，最大路径和的值
class Solution {
public:
  unordered_map<TreeNode *, int> dp_;
  int ans_{numeric_limits<int>::min()};
  int maxPathSum(TreeNode *root) {
    dfs(root);
    return ans_;
  }
  void dfs(TreeNode *node) {
    if (node->left == nullptr && node->right == nullptr) {
      dp_[node] = node->val;
      ans_ = max(ans_, node->val);
      return;
    }
    if (node->left != nullptr) {
      dfs(node->left);
    }
    if (node->right != nullptr) {
      dfs(node->right);
    }
    int val = node->val;
    val = max(val, dp_[node->left] + node->val);
    val = max(val, dp_[node->right] + node->val);
    dp_[node] =
        val; // 注意这里要先更新dp[],再计算node是路径中的点（非端点）的情况
    val = max(val, dp_[node->left] + dp_[node->right] + node->val);
    ans_ = max(ans_, val);
  }
};