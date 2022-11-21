class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        int idx = 0;
        while(1) {
            bool all_the_same = true;
            if(idx >= strs[0].size())
                break;
            char c = strs[0][idx];
            for(int i = 0; i < strs.size(); i++) {
                if(idx >= strs[i].size() || strs[i][idx] != c) {
                    all_the_same = false;
                    break;
                }
            }
            if(all_the_same == true)
                ret += c;
            else
                break;
            idx += 1;
            
        }
        return ret;
    }
};