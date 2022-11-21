class Solution {
public:
    int romanToInt(string s) {
        map<char, int> symbol_to_value;
        symbol_to_value['I'] = 1;
        symbol_to_value['V'] = 5;
        symbol_to_value['X'] = 10;
        symbol_to_value['L'] = 50;
        symbol_to_value['C'] = 100;
        symbol_to_value['D'] = 500;
        symbol_to_value['M'] = 1000;
        
        int ret = 0, now_max = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            int value = symbol_to_value[s[i]];
            if(value < now_max)
                ret -= value;
            else
                ret += value, now_max = value;
        }
        return ret;
    }
};