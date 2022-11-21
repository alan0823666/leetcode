class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int stored_water = 0;
        int leftmax = 0, rightmax = 0;
        int left = 0, right = n - 1;
        while(left <= right){
            if(a[left] <= a[right]){
                stored_water += max(0, leftmax - a[left]);
                leftmax = max(leftmax, a[left]);
                left++;
            }
            else{
                stored_water += max(0, rightmax - a[right]);
                rightmax = max(rightmax, a[right]);
                right--;
            }
        }
        return stored_water;
    }
};