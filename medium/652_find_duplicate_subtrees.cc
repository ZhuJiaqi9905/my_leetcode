#include <bits/stdc++.h>
using namespace std;
/// 思路是把子树做一个序列化的表示，这里的表示方法是用一个三元组：（val, left_subtree.idx, right_subtree.idx)。
/// 其中idx是一个树的编号。相同的树编号相同，是在dfs的时候给树编好的。
/// 然后只要是三元组相同的就是相同的子树。
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
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    dfs(root);
    return {repeat.begin(), repeat.end()};
  }
  int dfs(TreeNode *node) {
    if (!node) {
      return 0;
    }
    auto tri = tuple{node->val, dfs(node->left), dfs(node->right)};
    if (auto it = seen.find(tri); it != seen.end()) {
      repeat.insert(it->second.first);
      return it->second.second;
    } else {
      seen[tri] = {node, ++idx};
      return idx;
    }
  }

private:
  static constexpr auto tri_hash =
      [fn = hash<int>()](const tuple<int, int, int> &o) -> size_t {
    auto &&[x, y, z] = o;
    return (fn(x) << 24) ^ (fn(y) << 8) ^ fn(z);
  };

  unordered_map<tuple<int, int, int>, pair<TreeNode *, int>, decltype(tri_hash)>
      seen{0, tri_hash};
  unordered_set<TreeNode *> repeat;
  int idx = 0;
};