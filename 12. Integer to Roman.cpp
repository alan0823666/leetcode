class Solution {
public:
    string mul(const int& x, const string& s) {
        string ret = "";
        for(int i = 0; i < x; i++)
            ret += s;
        return ret;
    }
    string intToRoman(int num) {
        string ret = "";
        ret += mul( (num/1000), "M");
        num -= (num/1000) * 1000;
        
        ret += mul((num/900) , "CM");
        num -= (num/900) * 900;
        
        ret += mul((num/500) , "D");
        num -= (num/500) * 500;
        
        ret += mul((num/400) , "CD");
        num -= (num/400) * 400;
        
        ret += mul((num/100) , "C");
        num -= (num/100) * 100;
        
        ret += mul((num/90) , "XC");
        num -= (num/90) * 90;
        
        ret += mul((num/50) , "L");
        num -= (num/50) * 50;
        
        ret += mul((num/40) , "XL");
        num -= (num/40) * 40;
        
        ret += mul((num/10) , "X");
        num -= (num/10) * 10;
        
        ret += mul((num/9) , "IX");
        num -= (num/9) * 9;
        
        ret += mul((num/5) , "V");
        num -= (num/5) * 5;
        
        ret += mul((num/4) , "IV");
        num -= (num/4) * 4;
        
        ret += mul((num/1) , "I");
        num -= (num/1) * 1;
        
        return ret;
    }
};