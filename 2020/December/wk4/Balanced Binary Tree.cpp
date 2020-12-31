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
private:
    bool isHeightBalanced(TreeNode* root, int &h) {
        if (!root) return true;
        
        int lh = 0, rh = 0;
        bool ret = isHeightBalanced(root->left, lh) && isHeightBalanced(root->right, rh);
        int diff = lh > rh ? lh - rh : rh -lh;
        if (ret && (diff == 0 || diff == 1)) {
            h =  max(lh +1, rh +1);
            return ret;
        }
        return false;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        
        int h = 0;
        bool ret = isHeightBalanced(root, h);
        
        return ret;
    }
};
