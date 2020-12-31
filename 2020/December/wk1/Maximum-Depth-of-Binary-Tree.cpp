class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return lh>rh ? lh+1 : rh+1;
    }
};
