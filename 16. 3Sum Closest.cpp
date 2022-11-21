class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closet_diff = 100000;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int L = i + 1, R = nums.size() - 1;
            while(L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                int diff = sum - target;
                if(abs(diff) < abs(closet_diff))
                    closet_diff = diff;
                if(sum == target) {
                    return target;
                }
                else if(sum < target)
                    L += 1;
                else
                    R -= 1;
            }
        }
        return target + closet_diff;
    }
};