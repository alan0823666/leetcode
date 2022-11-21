class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret = 0;
        int prev = -1000;
        vector<int> new_nums(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == prev) {
                continue;
            }
            prev = nums[i];
            new_nums[ret] = nums[i];
            ret += 1;
           
        }
        nums = new_nums;
        return ret;
    }
};