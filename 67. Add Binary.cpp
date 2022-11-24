class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        int n = max(n1, n2);
        n += 1;
        string ret;
        ret.resize(n);
        for(int i = 0; i < n-n1; i++)
            a.insert(a.begin(), '0');
        for(int i = 0; i < n-n2; i++)
            b.insert(b.begin(), '0');
        int carry = 0;
        for(int i = n - 1; i > 0; i--) {
            int x = a[i] - '0' + b[i] - '0'+ carry;
            if(x > 1) {
                carry = 1;
                x -= 2;
            }
            else {
                carry = 0;
            }
            ret[i] = x + '0';
        }
        ret[0] = carry + '0';
        if(ret[0] == '0')
            ret.erase(ret.begin());
        return ret;
    }
};