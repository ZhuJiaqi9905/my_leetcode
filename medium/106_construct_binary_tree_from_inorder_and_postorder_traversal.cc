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
class Solution {
public:
  unordered_map<int, int> index_;
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    for (int i = 0, n = inorder.size(); i < n; ++i) {
      index_[inorder[i]] = i;
    }
    return myBuildTree(inorder, postorder, 0, inorder.size() - 1, 0,
                       postorder.size() - 1);
  }

  TreeNode *myBuildTree(const vector<int> &inorder,
                        const vector<int> &postorder, int inorder_left,
                        int inorder_right, int postorder_left,
                        int postorder_right) {
    if (inorder_left > inorder_right) {
      return nullptr;
    }
    int postorder_root = postorder_right;
    int inorder_root = index_[postorder[postorder_root]];
    TreeNode *node = new TreeNode(postorder[postorder_root]);
    int size_right_tree = inorder_right - inorder_root;
    node->left =
        myBuildTree(inorder, postorder, inorder_left, inorder_root - 1,
                    postorder_left, postorder_root - size_right_tree - 1);

    node->right =
        myBuildTree(inorder, postorder, inorder_root + 1, inorder_right,
                    postorder_right - size_right_tree, postorder_right - 1);

    return node;
  }
};