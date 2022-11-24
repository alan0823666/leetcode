class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        int max;
        int max_contain_end;
        max_contain_end = max = nums[0];
        for(int i = 1 ; i < N; i++) {
            int x = nums[i];
            if(x + max_contain_end > x)
                max_contain_end = x + max_contain_end;
            else
                max_contain_end = x;
            if(max_contain_end > max)
                max = max_contain_end;
        }
        return max;
    }
};