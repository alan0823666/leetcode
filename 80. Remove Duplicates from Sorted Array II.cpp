class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind = 0;
        for (auto it : nums) {
            cout << it << " " << ind << endl;
            if (ind < 2 or it > nums[ind-2]) {
                nums[ind++] = it;
            }
        }
        return ind; // this will contain the no of unique elements in the array
    }
};