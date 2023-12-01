#include <queue>
#include <vector>
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
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }
    queue<TreeNode *> que;
    que.emplace(root);
    while (!que.empty()) {
      int s = que.size();
      for (int i = 0; i < s; ++i) {
        auto &node = que.front();
        if (i == s - 1) {
          res.emplace_back(node->val);
        }
        if (node->left != nullptr) {
          que.emplace(node->left);
        }
        if (node->right != nullptr) {
          que.emplace(node->right);
        }
        que.pop();
      }
    }
    return res;
  }
};