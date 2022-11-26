class Solution {
public:
    // can change to buttom-up
    int recursiom( vector <vector <int> > &dp, string w1, string w2, int x, int y) {
        if(dp[x][y] != -1)
            return dp[x][y];
        int a, b, c; // delete w1, delete w2, replace or the same
        if(w1[x-1] == w2[y-1]) {
            c = recursiom(dp, w1, w2, x-1, y-1);
            return c;
        }
        else
            c = recursiom(dp, w1, w2, x-1, y-1) + 1;
        a = recursiom(dp, w1, w2, x-1, y) + 1;
        b = recursiom(dp, w1, w2, x, y-1) + 1;
        dp[x][y] = min(a, min(b, c));
        return dp[x][y];
    }
    int minDistance(string word1, string word2) {
        //insert in word1 equal to delete in word2
        //ex : abc + d =  abcd :: abc = abcd - d
        //so only to use dp and makesure every char have posibilty to be delete 
        //and replace equal to delete w1, w2 in the same time
        int n1 = word1.size(), n2 = word2.size();
        vector <vector <int> > dp(n1+1, vector<int> (n2+1));
        for(int i = 0; i <= n1; i++)
            for(int j = 0; j <= n2; j++)
                dp[i][j] = -1;
        dp[0][0] = 0;
        for(int i = 1; i <= n2; i++)
            dp[0][i] = i;
        for(int i = 1; i <= n1; i++)
            dp[i][0] = i;
        return recursiom(dp, word1, word2, n1, n2);
    }
};