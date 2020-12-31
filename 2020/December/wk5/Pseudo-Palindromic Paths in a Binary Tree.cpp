class Solution {
private:
    bool isvalid(vector<int> &arr) {
        int odd = false;
        
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i]%2) {
                if (!odd) {
                    odd = true;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
    
    int checkPal(TreeNode* root, vector<int> &arr) {
         if (!root) {
             return 0;
         } else if  (root && !root->left && !root->right) {
            arr[root->val-1]++;
            bool rc = isvalid(arr);
            arr[root->val-1]--;
            return rc ? 1 : 0;
        }
        
        int l = 0, r = 0;
        arr[root->val-1]++;
        if (root->left)
            l = checkPal(root->left, arr);
        if (root->right)
            r = checkPal(root->right, arr);
        
        arr[root->val-1]--;
        
        return l+r;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> arr(9, 0);
        return checkPal(root, arr);
    }
};
