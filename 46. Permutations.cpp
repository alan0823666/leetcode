class Solution {
public:
    vector<vector<int>> ans;
    void recursion(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            vector<int> tmp(nums);
            ans.push_back(tmp);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            int tmp = nums[idx];
            nums[idx] = nums[i];
            nums[i] = tmp;
            recursion(nums, idx+1);
            tmp = nums[idx];
            nums[idx] = nums[i];
            nums[i] = tmp;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
            recursion(nums, 0);
            return ans;
    }
};