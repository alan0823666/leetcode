class Solution {
public:
    string minWindow(string s, string t) {
        // window = [0, R] -> is contained
        // shirnk untill not contain -> [L, R] :: [L-1, R](is contained)
        // expand R untill contain -> [L, R']
        // repeat until R >= s.size()

        int n1 = s.size(), n2 = t.size();
        map <char, int> over_num_map;
        for(int i = 0; i < n1; i++) {
            if(over_num_map[s[i]] == 0)
                over_num_map[s[i]] = 1;
            else    
                over_num_map[s[i]] += 1;
        }
        for(int i = 0; i < n2; i++) {
            if(over_num_map[t[i]] == 0)
                return "";
            else
                over_num_map[t[i]] -= 1;
        }
        int ret = INT_MAX;
        int ret_st_idx = -1;
        string ret_string = "";
        int L = 0, R = n1-1;
        while(over_num_map[s[R]] > 0) {
            over_num_map[s[R]] -= 1;
            R -= 1;
        }
        if(R - L + 1 < ret) {
            ret = R - L + 1;
            ret_st_idx = L;
        }
        while(R < n1) {
            if(over_num_map[s[L]] > 0) {
                over_num_map[s[L]] -= 1;
                L++;
                if(R - L + 1< ret) {
                    ret = R - L + 1;
                    ret_st_idx = L;
                }
                
            }
            else {
                R++;
                over_num_map[s[R]] += 1;
            }
        }
        ret_string = s.substr(ret_st_idx, ret);
        return ret_string;
    }
};