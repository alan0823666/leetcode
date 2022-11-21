class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map <int, int> my_map;
        for(int i = 0; i < nums.size(); i++)
            my_map[nums[i]] = 1;
        for(int i = 1; i <= 2147483647; i++)
            if(my_map[i] == 0)
                return i;
        return 0;
    }
};