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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth;
        return lcaDeepestLeaves(root, depth);
    }
    
private:
    TreeNode* lcaDeepestLeaves(TreeNode* root,  int &depth) {
        if (!root) {
            depth = 0;
            return nullptr;
        }
        
        int ld, rd;
        TreeNode* l = lcaDeepestLeaves(root->left, ld);
        TreeNode* r = lcaDeepestLeaves(root->right, rd);
        
        depth = ld > rd ? ld + 1 : rd + 1;
        return ld == rd ? root : ld > rd ? l : r;
     }

};
