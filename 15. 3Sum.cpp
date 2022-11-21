class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i = 0; i < nums.size(); i++) {
            if(i >= 1 && nums[i-1] == nums[i])
                continue;
            
            int L = i + 1, R = nums.size() - 1;
            while(L < R) {
                if(nums[i] + nums[L] + nums[R] == 0) {
                    vector<int> tmp = {nums[i], nums[L], nums[R]};
                    ret.push_back(tmp);
                    while(L+1 < R && nums[L+1] == nums[L])
                        L += 1;
                    while(R-1 > L && nums[R-1] == nums[R])
                        R -= 1;
                    L += 1;
                    R -= 1;
                }
                else if(nums[i] + nums[L] + nums[R] < 0)
                    L += 1;
                else
                    R -= 1;
            }
        }
        return ret;
    }
};