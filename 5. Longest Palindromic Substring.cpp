class Solution {
public:
    int extend(int a, int b, int N, string s) {
        int i = 0;
        while (a-i>=0 && b+i<N && s[a-i] == s[b+i]) i++;
            return i;
    }
    string longestPalindrome(string t) {
        char s[1001 * 2];
	    int z[1001 * 2];
	    int N = t.size();
 
    // t穿插特殊字元，存放到s。
    // （實際上不會這麼做，都是細算索引值。）
        for(int i = 0; i < 1001*2; i++)
            s[i] = '.';
        for (int i=0; i<N; ++i) s[i*2+1] = t[i];
 
        N = N*2+1;
	    s[N] = '\0';
 
    // Manacher's Algorithm
	// https://medium.com/hoskiss-stand/manacher-299cf75db97e
        z[0] = 1;
        int L, R;
        L = R = 0;
        for (int i=1; i<N; ++i) {
            int ii = L - (i - L);   // i的映射位置
            int n = R + 1 - i;
 
            if (i > R) {
                z[i] = extend(i, i, N, s);
                L = i;
                R = i + z[i] - 1;
            }
            else if (z[ii] == n) {
                z[i] = n + extend(i-n, i+n, N, s);
                L = i;
                R = i + z[i] - 1;
            }
            else {
            z[i] = min(z[ii], n);
            }
        }
 
    // 尋找最長迴文子字串的長度。
        int n = 0, p = 0;
        
        for (int i=0; i<N; ++i)
            if (z[i] > n)
                n = z[p = i];
        
        // 記得去掉特殊字元。
        //cout << "最長迴文子字串的長度是" << p;
        string ret = "";
        // 印出最長迴文子字串，記得別印特殊字元。
        for (int i=p-z[p]+1; i<=p+z[p]-1; ++i)
            if (i & 1)
                ret += s[i];
        return ret;
        }
        
}