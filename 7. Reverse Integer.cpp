class Solution {
public:
    int reverse(int x) {
        //2147483647 ~ -2147483648
        
        int x_is_minus = 0;
        if(x < 0) {
            x_is_minus = 1;
            if(x == -2147483648)
                return 0;
            x = -x;
        }
        
        int digit[10];
        for(int i = 0; i < 10; i++) {
            int R = pow(10, 10-i-1);
            digit[i] = x/R;
            x = x - digit[i] * R;
        }
        /*
        for(int i = 0 ; i < 10; i++)
            cout << digit[i] << " ";
        */
        int bound[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        
        int ret = 0;
        int less_than_bound = 0;
        int vaild_digit_num = 10;
        
        for(int i = 0; i < 10; i++)
            if(digit[i] != 0) {
                vaild_digit_num -= i;
                break;
            }
        if(vaild_digit_num < 10)
            less_than_bound = 1;
        
        for(int i = 0; i < vaild_digit_num; i++) {
            int digit_idx = 10 - i - 1;
            if(less_than_bound == 0) 
                if(digit[digit_idx] > bound[i])
                    return 0;
                else if(digit[digit_idx] < bound[i])
                    less_than_bound = 1;
            ret += digit[digit_idx] * pow(10, vaild_digit_num-i-1);
            
        }
        if(x_is_minus == 1)
            ret = -ret;
        return ret;
    }
};