class Solution {
public:    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int end = n-1;
        for(int i = n-2; i >= 0; i--){
            if(i+nums[i] >= end) end = i; // i can reach end -> become new end
        }
        return end == 0;
    }
};