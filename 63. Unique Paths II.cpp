class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int R = obstacleGrid.size();
        int C = obstacleGrid[0].size();
        int dp[R][C];
        memset(dp, 0, R*C*sizeof(int));
        if(obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++) {
                if(i == 0 && j == 0)
                    continue;
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int x, y;
                x = (i - 1 < 0)? 0 : dp[i-1][j];
                y = (j - 1 < 0)? 0 : dp[i][j-1];
                dp[i][j] = x + y;
            }
        return dp[R-1][C-1];
    }
};