#include <deque>
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    deque<TreeNode *> que;
    if (root == nullptr) {
      return ans;
    }
    que.emplace_back(root);
    unsigned int flag = 0;
    while (!que.empty()) {
      vector<int> nums;
      int n = que.size();
      if (flag) {
        for (int i = n - 1; i >= 0; --i) {
          nums.emplace_back(que[i]->val);
        }
      } else {
        for (int i = 0; i < n; ++i) {
          nums.emplace_back(que[i]->val);
        }
      }
      ans.emplace_back(std::move(nums));
      for (int i = 0; i < n; ++i) {
        auto node = que.front();
        que.pop_front();
        if (node->left != nullptr) {
          que.emplace_back(node->left);
        }
        if (node->right != nullptr) {
          que.emplace_back(node->right);
        }
      }
      flag ^= 1;
    }
    return ans;
  }
};

int main() {}