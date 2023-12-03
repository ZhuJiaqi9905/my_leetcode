#include <unordered_map>
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
  unordered_map<int, int> index;
  TreeNode *myBuildTree(const vector<int> &preorder, const vector<int> &inorder,
                        int preorder_left, int preorder_right, int inorder_left,
                        int inorder_right) {
    if (preorder_left > preorder_right) {
      return nullptr;
    }

    int preorder_root = preorder_left;
    int inorder_root = index[preorder[preorder_root]];

    // 先把根节点建立出来
    TreeNode *root = new TreeNode(preorder[preorder_root]);
    // 得到左子树中的节点数目
    int size_left_subtree = inorder_root - inorder_left;
    root->left = myBuildTree(preorder, inorder, preorder_left + 1,
                             preorder_left + size_left_subtree, inorder_left,
                             inorder_root - 1);
    // 构建右子树的时候需要用size_left_subtree计算preorder的偏移
    root->right =
        myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1,
                    preorder_right, inorder_root + 1, inorder_right);
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    for (int i = 0; i < n; ++i) {
      index.emplace(inorder[i], i);
    }
    return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};