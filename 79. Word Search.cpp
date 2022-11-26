class Solution {
public:
    bool dfs (vector<vector<char>>& board, string word, int r, int c, int l) {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[r].size())
            return false;
        if(board[r][c] != word[l])
            return false;
        if(l == word.size()-1)
            return true;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < 4; i++) {
            char x = board[r][c];
            board[r][c] = '%';
            if(dfs(board, word, r+dir[i][0], c+dir[i][1], l+1)) {
                return true;
            }
            board[r][c] = x;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // dfs
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(dfs(board, word, i, j, 0))
                    return true;
        
        return false;

        
    }
};