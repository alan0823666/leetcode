class Solution {
public:
    /*
    dp[i][j] : there is a way that s[i ~ n] == p[i ~ n] or not
    */
    bool isMatch(string s, string p) {
        bool dp[s.size() + 2][p.size() + 1];
        
        for(int i = 0; i < s.size() + 2; i++)
            for(int j = 0; j < p.size() + 1; j++)
                dp[i][j] = false;
        
        dp[s.size()][p.size()] = true;
        
        for(int i = s.size(); i >= 0; i--)
            for(int j = p.size() - 1; j >= 0; j--) {
                bool first_the_same = false;
                if(s[i] == p[j] || p[j] == '.')
                    first_the_same = true;
                if(j + 2 < p.size() + 1 && p[j+1] == '*')
                    dp[i][j] = dp[i][j+2] || first_the_same && dp[i+1][j];
                else
                    dp[i][j] = first_the_same && dp[i+1][j+1];
            }
        return dp[0][0];
    }
};