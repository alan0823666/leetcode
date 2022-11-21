class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> en_char(8);
        en_char[0] = "abc";
        en_char[1] = "def";
        en_char[2] = "ghi";
        en_char[3] = "jkl";
        en_char[4] = "mno";
        en_char[5] = "pqrs";
        en_char[6] = "tuv";
        en_char[7] = "wxyz";
        
        vector<string> X;
        if(digits.size() == 0)
            return X;
        int d1 = digits[0] - '0';
        for(int i = 0; i < en_char[d1-2].size(); i++) {
            string tmp = "";
            tmp += en_char[d1-2][i];
            X.push_back(tmp);
        }
        for(int T = 1; T < digits.size(); T++) {
            int d = digits[T] - '0';
            vector<string> Y;
            for(int i = 0; i < en_char[d-2].size(); i++) {
                for(int k = 0; k < X.size(); k++) {
                    string tmp = X[k] + en_char[d-2][i];
                    Y.push_back(tmp);
                }
            }
            X = Y;
        }
        
        return X;
    }
};