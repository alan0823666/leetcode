class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> new_nums(nums.size(), 0);
        int non_delete_num = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) {
                continue;
            }
            new_nums[non_delete_num] = nums[i];
            non_delete_num += 1;
        }
        nums = new_nums;
        return non_delete_num;
    }
};