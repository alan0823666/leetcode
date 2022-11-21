class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int N = matrix.size();
        vector< vector<int> > ret(N);
        for(int i = 0; i < N; i++)
            ret[i].resize(N);
        cout << N << endl;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                cout << i << " " << j << endl;
                ret[i][j] = matrix[N-j-1][i];
            }
        matrix = ret;
    }
};