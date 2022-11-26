class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret(1);

        for(int i = 0; i < nums.size(); i++) {
            int r_size = ret.size();
            for(int k = 0; k < r_size; k++) {
               // cout << i << k << endl;
                vector <int> tmp = ret[k];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};