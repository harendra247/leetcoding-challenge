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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        std::stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        
        while(root || !st.empty()) {
            if(root) {
                st.push(root);
                root=root->left;
                continue;
            }
            
            root = st.top();
            st.pop();
            
            // print here
            if (pre && root->val <= pre->val) return false;
            pre = root;
            root=root->right;
        }
        
        return true;
    }
};
