class Solution {
public:
    bool isMatch(string s, string p) {
        int N = s.size(), M = p.size();
        bool dp[N+1][M+1];  //len 0 ~ N, len 0 ~ M, len = 0 == empty set
        for(int i = 0; i < N+1; i++)
            for(int j = 0; j < M+1; j++)
                dp[i][j] = false;
        dp[0][0] = true; // empty set == empty set
        for(int j = 0; j < M && p[j] == '*'; j++) {
                dp[0][j+1] = true;
        }
        for(int i = 1; i < N+1; i++)
            for(int j = 1; j < M+1; j++) {
                if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        return dp[N][M];
    }
};