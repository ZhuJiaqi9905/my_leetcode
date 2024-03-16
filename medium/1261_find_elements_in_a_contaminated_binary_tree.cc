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

class FindElements {
public:
  FindElements(TreeNode *root) {
    root->val = 0;
    dfs(root);
  }
  set<int> nums;
  bool find(int target) { return nums.find(target) != nums.end(); }
  void dfs(TreeNode *root) {
    nums.insert(root->val);
    if (root->left != nullptr) {
      root->left->val = root->val * 2 + 1;
      dfs(root->left);
    }
    if (root->right != nullptr) {
      root->right->val = root->val * 2 + 2;
      dfs(root->right);
    }
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
int main() {}