class Solution {
public:
    string convert(string s, int numRows) {
        
        int len = s.size();
        char ret[len + 1];
        // for example 
        // numRows = 4 >>> N = 4+(4-2)
        // re_group to %0, %1:5, %2:4, %3
        int N = numRows + numRows - 2;
        int idx = 0;
        if(N == 0 || N == 1)
            return s;
        for(int i = 0; i < numRows; i++) {
            int g1 = i, g2 = (N - i) % N;
            if(g1 == g2) {
                for(int k = 0; k * N + g1 < len; k++) {
                    ret[idx] = s[k * N + g1];
                    idx += 1;
                    
                }
            }
            else {
                for(int k = 0; k < len ; k++) {
                    
                    if(k * N + g1 >= len)
                        break;
                    ret[idx] = s[k * N + g1];
                    idx += 1;
                    
                    
                    if(k * N + g2 >= len)
                        break;
                    ret[idx] = s[k * N + g2];
                    idx += 1;
                    
                }
            }
        }
        ret[len] = '\0';
        return ret;
    }
};