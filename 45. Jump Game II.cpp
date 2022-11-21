class Solution {
public:
    int jump(vector<int>& nums) {
        int N = nums.size();
        int min_step[N];
        for(int i = 0; i < N; i++)
            min_step[i] = 1000000;
        min_step[0] = 0;
        for(int i = 0 ; i < N; i++) {
            for(int x = 0; x <= nums[i] && i+x < N; x++)
                min_step[i+x] = min(min_step[i+x], min_step[i]+1);

        }
        return min_step[N-1];
    }
};