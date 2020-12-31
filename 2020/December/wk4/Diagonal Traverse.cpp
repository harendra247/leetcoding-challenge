class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        
        int i = 0, r = 0, c = 0, m = matrix.size(), n = matrix[0].size();
        
        while (i < m*n) {
            res.push_back(matrix[r][c]);
            
            if ((r+c)%2 == 0) {
                if (c == n-1) {
                    r++;
                } else if (r == 0) {
                    c++;
                } else {
                    r--, c++;
                }
            } else {
                if (r == m-1) {
                    c++;
                } else if (c == 0) {
                    r++;
                } else {
                    r++, c--;
                }
            }
            i++;
        }
        
        return res;
    }
};
