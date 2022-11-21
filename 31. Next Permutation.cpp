class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //[a] [x_vector] 
        // if x_vector is the end -> a 變成 x_vector 裡面比a大一點的element, x_vector換a進去 然後由小到大排
        //                           這就是x_vector的first
        
        // if x_vector is not the end -> x_vector -> next (在拆分成a + x'. 直到變成x' == the end)
        
        
        // x_vector == the end 就是他為由大到小
        
        // 統合來說 就是從後面開始找 , 找到不大於上一個的值 . 然後把比他大一點的拿到這個位置, 然後把後面的由小到大
        
        
        
        int len = nums.size();
        int prev = -1;
        int idx = -1;
        for(int i = len - 1; i >= 0; i--) {
            if(nums[i] < prev) {
                idx = i; 
                break;
            }
            else
                prev = nums[i];
        }
        //cout << idx;
        if(idx == -1)
            sort(nums.begin(), nums.end());
        else {
            int greater_than_idx_id = 0;
            for(int i = idx + 1; i < len; i++)
                if(nums[i] > nums[idx]) {
                    greater_than_idx_id = i; 
                }
                else
                    break;
            int tmp = nums[idx];
            nums[idx] = nums[greater_than_idx_id];
            nums[greater_than_idx_id] = tmp;
            sort(nums.begin() + idx + 1, nums.end());
        }        
        
        
    }
};