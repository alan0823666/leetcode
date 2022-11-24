class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        for(int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += 1;
            if(digits[i] == 10) {
                digits[i] = 0;
                if(i == 0)
                    carry = true;
            }
            else
                break;
        }
        if(carry)
            digits.insert(digits.begin(),1);
        return digits;
    }
};