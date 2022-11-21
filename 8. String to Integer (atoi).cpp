class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        int digit_idx = 0;
        int digits[11];
        while(s[idx] == ' ')
            idx += 1;
        
        int is_positive = 1;
        
        if(s[idx] == '-')
            is_positive = 0;
        else if(s[idx] == '+')
            is_positive = 1;
        else if(isdigit(s[idx]) && s[idx] != '0') {
            digits[digit_idx] = s[idx] - '0';
            digit_idx += 1;
        }
        else if(isdigit(s[idx]) == 0)
            return 0;
        idx += 1;
        
        //if not start, do erase zero process
        if(digit_idx == 0) {
            while(s[idx] == '0')
                idx += 1;
            if(isdigit(s[idx]) == 0)
                return 0;
        }
        
        while(idx < s.size() && isdigit(s[idx])) {
            digits[digit_idx] = s[idx] - '0';
            digit_idx += 1;
            idx += 1;
            if(digit_idx > 10)
                if(is_positive == 1)
                    return 2147483647;
                else
                    return -2147483648;
        }
        int num_of_digit = digit_idx;
        int bound[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        int less_than_bound = 0;
        int out_of_bound = 0;
        int ret = 0;
        if(num_of_digit < 10)
            less_than_bound = 1;
        for(int i = 0; i < num_of_digit; i++) {
            if(less_than_bound == 0)
                if(digits[i] > bound[i]) {
                    out_of_bound = 1;
                    break;
                }
                else if(digits[i] < bound[i])
                    less_than_bound = 1;
            ret += digits[i] * pow(10, num_of_digit - i - 1);
        }
        if(out_of_bound == 1)
            if(is_positive == 1)
                return 2147483647;
            else
                return -2147483648;
        else
            if(is_positive == 1)
                return ret;
            else
                return -ret;
        
        
        
    }
};