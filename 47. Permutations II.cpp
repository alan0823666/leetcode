class Solution {
public:
    vector<vector<int>> ans;
    void recursion(vector<int>& nums, int idx) {
        if(idx == nums.size()) {
            vector<int> tmp(nums);
            ans.push_back(tmp);
            return;
        }
        map<int, int> dup;
        for(int i = idx; i < nums.size(); i++) {
            if(dup[nums[i]] == 1)
                continue;
            dup[nums[i]] = 1;
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        recursion(nums, 0);
        return ans;
    }
};