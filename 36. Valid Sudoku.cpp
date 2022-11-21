class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, int> my_hash_table;
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    continue;
                //cout << i << " " << j << endl;
                string x = to_string(board[i][j]) + "row" + to_string(i);
                string y = to_string(board[i][j]) + "col" + to_string(j);
                string z = to_string(board[i][j]) + "block" + to_string(i/3) +  to_string(j/3);
                
                if(my_hash_table[x] == 1 || my_hash_table[y] == 1 || my_hash_table[z] == 1)
                    return false;
                
                my_hash_table[x] = 1;
                my_hash_table[y] = 1;
                my_hash_table[z] = 1;
                    
            }
        }
        return true;
    }
};