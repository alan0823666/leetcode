class Solution {
public:
    
    int find_pivot(vector<int>& nums, int L, int R) {
        int M = (L + R) / 2;
        if(M == 0 || L >= R)
            return 0;
        if(nums[M-1] > nums[M])
            return M;
        if(nums[0] < nums[M])
            return find_pivot(nums, M+1, R);
        if(nums[0] > nums[M])
            return find_pivot(nums, L, M);
        return 0;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot_id = find_pivot(nums, 0, nums.size());
        cout << pivot_id << endl;
        int L = 0, R = nums.size();
        int ret = -1;
        while(L < R) {
            cout << L << " " << R << endl;
            int M = (L + R)/2;
            int M_rotated = M + pivot_id;
            if(M_rotated >= nums.size())
                M_rotated -=  nums.size();
            int x = nums[M_rotated];
            if(x == target)
                return M_rotated;
            if(x > target)
                R = M;
            else if(x < target)
                L = M+1;
        }
        return -1;

    }
};