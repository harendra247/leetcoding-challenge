class Solution {
private:
    
    int go (vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>> &memo) {
        if (i >= grid.size()) {
            return 0;
        }
        
        if (j1 < 0 || j2 < 0 || j1 >=grid[0].size() || j2 >=grid[0].size()) {
            return 0;
        }
        if(memo[i][j1][j2] != -1) return memo[i][j1][j2];
        
        int ans = 0, cur;
        cur = grid[i][j1] + grid[i][j2];
        if (j1 == j2) {
            cur -= grid[i][j1];
        }
        
        ans = max(ans, cur + go(grid, i+1, j1+1, j2+1, memo));
        ans = max(ans, cur + go(grid, i+1, j1+1, j2-1, memo));
        ans = max(ans, cur + go(grid, i+1, j1+1, j2, memo));
        ans = max(ans, cur + go(grid, i+1, j1-1, j2+1, memo));
        ans = max(ans, cur + go(grid, i+1, j1-1, j2-1, memo));
        ans = max(ans, cur + go(grid, i+1, j1-1, j2, memo));
        ans = max(ans, cur + go(grid, i+1, j1, j2+1, memo));
        ans = max(ans, cur + go(grid, i+1, j1, j2-1, memo));
        ans = max(ans, cur + go(grid, i+1, j1, j2, memo));
       
        return memo[i][j1][j2] = ans;
    }    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> memo (79, vector<vector<int>>(79, vector<int> (79, -1)));
        return go(grid, 0, 0, grid[0].size()-1, memo);
    }
};
