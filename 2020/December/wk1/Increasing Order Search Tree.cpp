class Solution {
TreeNode* newroot = nullptr;
TreeNode* curr = nullptr;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return newroot;
        
        increasingBST(root->left);
        if (!newroot) {
            newroot = new TreeNode(root->val);
            curr = newroot;
        } else {
            curr->right = new TreeNode(root->val);
            curr = curr->right;
        }
        increasingBST(root->right);
        return newroot;
    }
};
