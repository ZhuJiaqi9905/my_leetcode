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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* nd = root;
        while(!st.empty() || nd != nullptr){
            while(nd != nullptr){
                st.push(nd);
                nd = nd->left;
            }
            nd = st.top();
            st.pop();
            ans.push_back(nd->val);
            nd = nd->right;
        }
        return ans;
    }
};