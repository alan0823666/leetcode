class Solution {
public:
    map <pair <int, int>, int> path_num;
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        pair<int, int> tmp = make_pair(m, n);
        if(path_num[tmp] != 0)
            return path_num[tmp];
        else {
             int r = uniquePaths(m-1, n) + uniquePaths(m, n-1);
             path_num[tmp] = r;
             return r;
        }
    }
};