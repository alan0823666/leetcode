class Solution {
public:
    //if (isdigit(atoi(line.c_str())))
    //    return true;
    bool is_digit(string s) {
        for(int i = 0 ; i < s.size(); i++) {
            if(isdigit(s[i])) {
                continue;
            }
            else
                return false;
        }
        return true;
    }
    bool s1_isNumber(string s) {
        if(s[0] == '-' || s[0] == '+')
            s.erase(s.begin());
        if(s.size() == 0 || s[0] == '-' || s[0] == '+' || (s[0] == '.' && s.size() == 1))
            return false;
        int idx_dot = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '.') {
                idx_dot = i;
            }
        }
        if(idx_dot != -1) {
            string s1(s.begin(), s.begin()+idx_dot);
            string s2(s.begin()+idx_dot+1, s.end());
            if(s1 == "" || is_digit(s1))
                if(s2 == "" || is_digit(s2))
                    return true;
            return false;
        }
        else {
            cout << "adf  " << s;
            return (s == "" || is_digit(s));
        }
        return true;
    }
    bool isNumber(string s) {
        int idx_e = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'e' || s[i] == 'E')
                idx_e = i;
            else if(isdigit(s[i]) == 0 && s[i] != '.' && s[i] != '+' && s[i] != '-')
                return false;
        }
        
        cout << " eee " << idx_e << endl;
        if(idx_e == 0 || idx_e == s.size()-1)
            return false;
        if(idx_e != -1) {
            string s1(s.begin(), s.begin()+idx_e);
            string s2(s.begin()+idx_e+1, s.end());
            if(s1.size() == 0 || s2.size() == 0)
                return false;
            cout << s1  << " " << s2 << endl;
            for(int k = 0; k < s2.size(); k++)
                if(s2[k] == '.')
                    return false;

            return s1_isNumber(s1) && s1_isNumber(s2);
        }
        else
            return s1_isNumber(s);
        return true;
    }
};