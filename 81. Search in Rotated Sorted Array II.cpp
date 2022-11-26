class Solution {
public:


    bool search(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;

        if(nums.size() == 1)
            return nums[0] == target;
        if(nums.size() == 2)
            return nums[0] == target || nums[1] == target;
        
        // remove same pivot
        while(nums[L] == nums[R] && R != L && R > L) {
            if(nums[L] == target)
                return true;
            L++, R--;
        }
        if(L > R)
            return false;
        if(nums[L] == target || nums[R] == target)
                return true;
            while(L < R) {
                int mid = (L + R)/2;
                cout << mid << endl;
                if(nums[mid] == target || nums[R] == target || nums[L] == target)
                    return true;
                if(nums[L] == nums[mid]) {
                    L++;
                    continue;
                }
                if(nums[R] == nums[mid]) {
                    R--;
                    continue;
                }
                if(nums[L] < nums[mid]) {
                    if(nums[mid] > target && nums[L] < target)
                        R = mid - 1;
                    else
                        L = mid + 1;
                }
                else {
                    if(nums[mid] < target && nums[R] > target)
                        L = mid + 1;
                    else
                        R = mid - 1;
                }

            }

        return false;
    }
};