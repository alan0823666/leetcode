class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size() - 1;
        int max_area = 0;
        while(L < R) {
            int area = (R - L) * min(height[L], height[R]);
            max_area = max(max_area, area);
            if(height[L] < height[R])
                L += 1;
            else
                R -= 1;
        }
        return max_area;
    }
};