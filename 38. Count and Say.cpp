class Solution {
public:
    string one_iter(string &s) {
        //cout  << "s == "<< s << endl;
        int prev_same_count = 1;
        string rret = "";
        for(int i = 1; i < s.size(); i++) {
            if(s[i-1] == s[i]) {
                prev_same_count += 1;
            }
            else {
                int total_same = prev_same_count;
                string be_pushed = to_string(total_same);
                //cout << be_pushed << endl;
                rret += be_pushed;
                rret += s[i-1];
                prev_same_count = 1;
            }
        }
        if(prev_same_count != 0) {
            int total_same = prev_same_count;
            string be_pushed = to_string(total_same);
            //cout << be_pushed << endl;
            rret += be_pushed;
            rret += s[s.size() - 1];
        }
        return rret;
        
    }
    string countAndSay(int n) {
        string ret = "1";
        for(int i = 0; i < n-1; i++) {
            ret = one_iter(ret);
        }
        return ret;
    }
};