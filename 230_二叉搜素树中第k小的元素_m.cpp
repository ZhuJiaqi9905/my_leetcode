/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
    void dfs(TreeNode* root, int k){
        if(root == nullptr){
            return;
        }
        if(idx == k){
            return;
        }
        dfs(root->left, k);
        ++idx;
        if(idx == k){
            ans = root->val;
        }
        dfs(root->right, k);
    }
};