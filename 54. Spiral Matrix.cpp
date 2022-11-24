class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = 0, c = 0;
        vector<int> ret;
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r_length = matrix.size();
        int c_length = matrix[0].size();
        int r_upper_bound = r_length-1, c_upper_bound = c_length-1;
        int r_lower_bound = 0, c_lower_bound = 0;
        //cout << r_length << " " << c_length << endl;
        int direction_idx = 0;
        int nums = r_length * c_length;
        for(int i = 0; i < nums; i++) {
            cout << r << " "<< c << " "<< matrix[r][c] << endl;
            ret.push_back(matrix[r][c]);
            int new_r = r + direction[direction_idx][0];
            int new_c = c + direction[direction_idx][1];
            if(new_r > r_upper_bound || new_r < r_lower_bound || new_c > c_upper_bound || new_c < c_lower_bound) {
                if(direction_idx == 0)
                    r_lower_bound += 1;
                else if(direction_idx == 1)
                    c_upper_bound -= 1;
                else if(direction_idx == 2)
                    r_upper_bound -= 1;
                else if(direction_idx == 3)
                    c_lower_bound += 1;
                direction_idx += 1;
                if(direction_idx >= 4)
                    direction_idx = 0;
                new_r = r + direction[direction_idx][0];
                new_c = c + direction[direction_idx][1];
            }
            r = new_r;
            c = new_c;
            
        }
        return ret;
    }
};