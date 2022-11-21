class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
        if(target_id == -1)
            return L;
        else
            return target_id;
    }
};