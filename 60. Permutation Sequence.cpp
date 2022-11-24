class Solution {
public:
    map <int, int> n_stair;
    vector <int> ret;
    void recursion(vector<int> &vec, int n, int k) {
        if(n == 1) {
            ret.push_back(vec[0]);
            return;
        }
        //cout << "n == " << n << endl;
        //cout << "..n == " << n_stair[n] << endl;
        int type_size = n_stair[n]/n ;
        int x = k/type_size;
        int y = k % type_size;
        cout << x << " " << y << " " << k << endl;
        if(y == 0) {
            ret.push_back(vec[x-1]);
            vec.erase(vec.begin() + x - 1);
            for(int i = vec.size()-1 ; i >= 0; i--)
                ret.push_back(vec[i]);
            return;
        }
        ret.push_back(vec[x]);
        vec.erase(vec.begin() + x);
        recursion(vec, n-1, y);

    }
    string getPermutation(int n, int k) {
        int stair = 1;
        for(int i = 1; i < 10; i++) {
            stair *= i;
            n_stair[i] = stair;
        }
        vector <int> vec;
        for(int i = 1 ; i <= n; i++)
            vec.push_back(i);
        recursion(vec, n, k);
        string ret_string = "";
        for(int i = 0; i < n ; i++) {
            cout << ret[i] << " ";
            char c = ret[i] + '0';
            ret_string += c;
        }
        return ret_string;
    }
};