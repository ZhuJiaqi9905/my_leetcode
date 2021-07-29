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
 #include<vector>
 #include<stack>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *nd = root;
        vector<int> ans;
        while(!st.empty() || nd != nullptr){
            if(nd == nullptr){
                nd = st.top();
                st.pop();
            }
            ans.push_back(nd->val);
            if(nd->right != nullptr){
                st.push(nd->right);
            }
            nd = nd->left;
        }
        return ans;
    }
};