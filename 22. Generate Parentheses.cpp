class Solution {
public:
    vector<string> solve(int n) {
        if(n == 0) return {""};
        
        vector<string> res;
        for(int i = 0; i <= n - 1; i++) {
            // inside i, and outside n - 1 - i
            
            // (i) + (n-1-i) + (1) = n
            vector<string> inSide = solve(i);
            vector<string> outSide = solve(n - 1 - i);
            for(string s1 : inSide) {
                for(string s2 : outSide) {
                    string cur = "(" +  s1 +  ")" + s2;
                    res.push_back(cur);
                }
            }
        }
        
        return res;
    }
    vector<string> generateParenthesis(int n) { 
        return solve(n);
    }
};