class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int dp[R][C];
        memset(dp, 0, R*C*sizeof(int));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++) {
                if(i == 0 && j == 0)
                    continue;
                int x = INT_MAX;
                int y = INT_MAX;
                if(i - 1 >= 0)
                    x = dp[i-1][j];
                if(j - 1 >= 0)
                    y = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(x, y);
            }
        return dp[R-1][C-1];
    }
};