class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        int l = 1, r = x/2 + 1;
        while(l < r) {
            long mid = (l + r)/2;
            if(mid * mid <= x && (mid + 1) * (mid + 1) > x)
                return mid;
            else if(mid * mid > x) {
                r = mid;
            }
            else
                l = mid + 1;
        }
        return 1;
    }
};