class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n<1) return {};
        int i = 1;
        
        int cs = 0, ce = n-1; //column start, column end
        int rs = 0, re = n-1; // row start, row end
        int dir = 0; // 0-> ltor, 1->ttob, 2->rtol, 3->btot;
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        while (i <= n*n) {
            if (dir == 0) {
                for (int j = cs; j <= ce; ++j) {
                   res[rs][j] = i++;
                }
                rs++;
            } else if (dir == 1) {
                for (int j = rs; j <= re; ++j) {
                   res[j][ce] = i++;
                }
                ce--;
            } else if (dir == 2) {
                for (int j = ce; j >= cs; --j) {
                   res[re][j] = i++;
                }
                re--;
            } else if (dir == 3) {
                for (int j = re; j >= rs; --j) {
                   res[j][cs] = i++;
                }
                cs++;
            }
            
            dir = ++dir % 4;
        }
        
        return res;
    }
};
