class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_L = 0, row_R = matrix.size();
        int row_mid = -1;
        while(row_L < row_R) {
            row_mid = (row_L + row_R)/2;
            if(matrix[row_mid][0] <= target && (row_mid + 1 >= matrix.size() || matrix[row_mid+1][0]        >target))      {
                break;
            }
            else if(matrix[row_mid][0] > target) {
                row_R = row_mid;
            }
            else
                row_L = row_mid+1;
        }
        if(row_mid == -1)
            return false;
        int L = 0, R = matrix[row_mid].size();
        int mid = -1;
        while(L < R) {
            mid = (L + R)/2;
            if(matrix[row_mid][mid] == target)
                return true;
            else if(matrix[row_mid][mid] > target)
                R = mid;
            else
                L = mid+1;

        }
        return false;

    }
};