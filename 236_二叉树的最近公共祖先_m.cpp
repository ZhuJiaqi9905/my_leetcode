/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode* lc = lowestCommonAncestor(root->left, p, q);
        TreeNode* rc = lowestCommonAncestor(root->right, p, q);
        if(lc == nullptr){
            return rc;
        }
        if(rc == nullptr){
            return lc;
        }
        return root;
    }
};