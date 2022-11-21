class Solution {
public:
    unordered_map<string, int> my_hash_table;
    char transfer[9] = {'1','2', '3', '4', '5', '6', '7', '8', '9'};
    bool solver(vector<vector<char>>& board, int R, int C) {
        if(R == 9 && C == 9)
            return true;
        
        if(R == 9) { 
            R = 0;
            C += 1;
        }
        if(board[R][C] != '.') {
            return solver(board, R+1, C);
        }
        else {
            bool exist_cur_solve = false;
            for(int val = 0; val < 9; val++) {
                char cur =  transfer[val];
                string x = to_string(cur) + "row" + to_string(R);
                string y = to_string(cur) + "col" + to_string(C);
                string z = to_string(cur) + "block" + to_string(R/3) +  to_string(C/3);
                
                if(my_hash_table[x] == 1 || my_hash_table[y] == 1 || my_hash_table[z] == 1)
                    continue;
                
                my_hash_table[x] = 1;
                my_hash_table[y] = 1;
                my_hash_table[z] = 1;
                board[R][C] = cur;
                if( solver(board, R+1, C) == false) {
                    my_hash_table[x] = 0;
                    my_hash_table[y] = 0;
                    my_hash_table[z] = 0;
                    board[R][C] = '.';
                    continue;
                }
                exist_cur_solve = true;
            }
            return exist_cur_solve;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
            for(int j = 8; j >= 0; j--) {
                if(board[i][j] == '.')
                    continue;
                string x = to_string(board[i][j]) + "row" + to_string(i);
                string y = to_string(board[i][j]) + "col" + to_string(j);
                string z = to_string(board[i][j]) + "block" + to_string(i/3) +  to_string(j/3);


                my_hash_table[x] = 1;
                my_hash_table[y] = 1;
                my_hash_table[z] = 1;
            }
        solver(board, 0, 0);
        
        
    }
    
                           
        
};