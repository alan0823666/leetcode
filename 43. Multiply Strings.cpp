class Solution {
public:
    string multiply(string num1, string num2) {
        int len_1 = num1.size();
        int len_2 = num2.size();
        string ret;
        vector <int> n1(len_1), n2(len_2);
        vector <int> ans(len_1 + len_2 + 1);
        for(int i = 0; i < len_1; i++)
            n1[i] = num1[i] - '0'; 
        
        for(int i = 0; i < len_2; i++)
            n2[i] = num2[i] - '0';
       // cout << n1 << " " << n2 << endl;
        for(int i = 0; i < len_1; i++) {
            for(int j = 0; j < len_2; j++) {
                int idx_1 = len_1  - i - 1, idx_2 = len_2 - j - 1;
                int tmp = n1[idx_1] * n2[idx_2];
                ans[i + j] += tmp;
            }
        }
        
        for(int i = 0; i < len_1 + len_2; i++) {
            int x = ans[i];
            ans[i] = x % 10;
            ans[i + 1] += x/10;
        }
        for(int i = 0 ; i < len_1 + len_2; i++)
            cout << ans[i];
        
        int st_point = 0;
        for(int i = len_1 + len_2 - 1; i >= 0; i--) {
            if(ans[i] != 0) {
                st_point = i;
                break;
            }
        }
        for(int i = st_point; i >= 0; i--) {
            char tmp = '0' + ans[i];
            ret += tmp;
        }
            
        return ret;
    }
};