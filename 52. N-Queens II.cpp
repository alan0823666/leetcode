class Solution {
public:
    int ret;
    bool exam(char** board, int r, int c, int N) {

        for(int i = 0; i < r; i++)
            if(board[i][c] == 'Q')
                return false;
        int idx_c1 = c-1, idx_c2 = c+1;
        for(int i = r-1; i >= 0; i--, idx_c1 -= 1, idx_c2 += 1) {
            if(idx_c1 >= 0)
                if(board[i][idx_c1] == 'Q')
                    return false;
            if(idx_c2 < N)
                if(board[i][idx_c2] == 'Q')
                    return false;
        }
        return true;
    }
    void recursion(char** board, int N, int r, int c) {
        if(exam(board, r, c, N) == false) {
            return;
        }
        if(r == N-1) {
            ret++;
            return;
        }
        board[r][c] = 'Q';
        
        for(int i = 0; i < N; i++) {
            recursion(board, N, r+1, i);
        }

        board[r][c] = '.';
        
        return;
    }
    int totalNQueens(int n) {
        char** board;
        board = (char**)malloc(sizeof(char*) * n);
        for(int i = 0; i < n; i++)
            board[i] = (char*)malloc(sizeof(char) * n);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                board[i][j] = '.';
        for(int i = 0; i < n; i++)
            recursion(board, n, 0, i);
        
        return ret;
    }
};