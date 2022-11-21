class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int L = 0, R = nums.size();
        int target_id = -1;
        while(L < R) {
            //cout << L << " " << R << endl;
            int M = (L + R) / 2;
            if(nums[M] == target) {
                target_id = M;
                break;
            }
            else if(nums[M] > target) {
                R = M;
            }
            else if(nums[M] < target) {
                L = M + 1;
            }
        }
        vector<int> ret = {-1, -1};
        if(target_id == -1) 
            return ret;
        //cout << target_id << endl;
        int left_bound = target_id;
        int right_bound = target_id;
        while(left_bound >= 0 && nums[left_bound] == target)
            left_bound -= 1;
        while(right_bound < nums.size() && nums[right_bound] == target)
            right_bound += 1;
        ret[0] = left_bound + 1;
        ret[1] = right_bound - 1;
        return ret;
        
    }
};