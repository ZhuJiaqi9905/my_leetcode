#include <vector>
using namespace std;
#include <deque>
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    deque<TreeNode *> que;
    if (root == nullptr) {
      return ans;
    }
    que.emplace_back(root);
    while (!que.empty()) {
      vector<int> nums;
      for (int i = 0, n = que.size(); i < n; ++i) {
        auto node = que.front();
        que.pop_front();
        nums.emplace_back(node->val);
        if (node->left != nullptr) {
          que.emplace_back(node->left);
        }
        if (node->right != nullptr) {
          que.emplace_back(node->right);
        }
      }
      ans.emplace_back(std::move(nums));
    }
    return ans;
  }
};