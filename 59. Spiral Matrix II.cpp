class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dir[4][2] = {{0 , 1}, {1 , 0}, {0 , -1}, {-1 , 0}};
        vector<vector<int>> ret(n);
        for(int i = 0 ; i < n; i++)
            ret[i].resize(n);
        int lower_r_bound = 0;
        int upper_r_bound = n-1;
        int lower_c_bound = 0;
        int upper_c_bound = n-1;
        int r = 0, c = 0;
        int dir_idx = 0;
        for(int i = 1; i <= n*n; i++) {
            ret[r][c] = i;
            cout << r << " " << c << endl; 
            int new_r = r + dir[dir_idx][0];
            int new_c = c + dir[dir_idx][1];
            if(new_r < lower_r_bound) {
                dir_idx = 0;
                lower_c_bound += 1;
                new_r = r + dir[dir_idx][0];
                new_c = c + dir[dir_idx][1];
            }
            else if(new_r > upper_r_bound) {
                dir_idx = 2;
                upper_c_bound -= 1;
                new_r = r + dir[dir_idx][0];
                new_c = c + dir[dir_idx][1];
            }
            else if(new_c < lower_c_bound) {
                dir_idx = 3;
                upper_r_bound -= 1;
                new_r = r + dir[dir_idx][0];
                new_c = c + dir[dir_idx][1];
            }
            else if(new_c > upper_c_bound) {
                dir_idx = 1;
                lower_r_bound += 1;
                new_r = r + dir[dir_idx][0];
                new_c = c + dir[dir_idx][1];
            }
            r = new_r;
            c = new_c;
        }
        return ret;
    }
};