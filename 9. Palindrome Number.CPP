class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        int origin_x = x;
        int y = 0;
        int less_than_bound = 0;
        int digit_x[10];
        for(int i = 0; i < 10; i++) {
            int R = pow(10, 10-i-1);
            digit_x[i] = x/R;
            x = x - digit_x[i] * R;
        }
        int bound[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        
        int start_non_zero_idx = 0;
        for(int i = 0; i < 10; i++) {
            start_non_zero_idx = i;
            if(digit_x[i] != 0)
                break;
        }
        if(start_non_zero_idx >= 1)
            less_than_bound = 1;
        for(int i = 9; i >= start_non_zero_idx; i--) {
            int R = pow(10, i - start_non_zero_idx);
            if(less_than_bound == 0) {
                if(digit_x[i] > bound[10-i-1])
                    return false;
                else if(digit_x[i] < bound[10-i-1])
                    less_than_bound = 1;
            }
            y += digit_x[i] * R;
        }
        if(origin_x == y)
            return true;
        else
            return false;
    }
};